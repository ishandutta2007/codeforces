#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define K 200
#define M 300001
vector <int> e[N];
int p[N],x[N],h[N],z,q[N],c,qi[N],qj[N],r[N],a[N],aa,w[N];
long long v[M+10000];
int g[M+10000];
int ins(int i,int j,int f){
    int k;
    long long t=(long long)i*N+j+1;
    for(k=t%M;v[k] && v[k]!=t;k++);
    if(!v[k]){
        v[k]=t;
        g[k]=f;
    }
    return g[k];
}
void add(int i,int j){
    if(j<i) swap(i,j);
    int k;
    long long t=(long long)i*N+j+1;
    for(k=t%M;v[k] && v[k]!=t;k++);
    if(v[k]==t)r[g[k]]++;
}
void edge(int i, int j){
    x[z]=j;
    p[z]=h[i];
    h[i]=z++;
}
void dfs(int i){
    int j;
    a[i]=aa;
    q[c++]=i;
    for(j=h[i];j>=0;j=p[j])
        if(a[x[j]]!=aa) dfs(x[j]);
}
void dfs2(int i){
    int j;
    a[i]=aa;
    q[i]=c;
    for(j=h[i];j>=0;j=p[j])
        if(a[x[j]]!=aa) dfs2(x[j]);
}
int main(){
    int i,j,k,n,l,t;
    scanf("%d%d",&n,&k);
    for(;k--;){
        scanf("%d%d%d",&i,&j,&l);i--;j--;
        e[l].push_back(i);
        e[l].push_back(j);
    }
    scanf("%d",&t);
    for(l=0;l<t;l++){
        scanf("%d%d",&i,&j);i--;j--;
        if(j<i) swap(i,j);
        qi[l]=i;
        qj[l]=j;
        w[l]=ins(i,j,l);
    }
    for(l=0;l<N;l++){
        if(e[l].size()==0) continue;
        z=0;
        aa++;
        for(i=0;i<e[l].size();h[e[l][i]]=-1,i++);
        for(i=0;i<e[l].size();edge(e[l][i],e[l][i+1]),edge(e[l][i+1],e[l][i]),i+=2);
        if(e[l].size()<K){
            for(i=0;i<e[l].size();i++)
                if(a[e[l][i]]!=aa){
                    c=0;
                    dfs(e[l][i]);
                    for(j=0;j<c;j++)
                        for(k=j+1;k<c;add(q[j],q[k]),k++);
                }
        }else{
            c=0;
            for(i=0;i<e[l].size();i++)
                if(a[e[l][i]]!=aa){c++;dfs2(e[l][i]);}
            for(i=0;i<t;i++)
                if(w[i]==i)
                    if(a[qi[i]]==aa && a[qj[i]]==aa && q[qi[i]]==q[qj[i]]) r[i]++;
        }
    }
    for(i=0;i<t;i++)
        if(w[i]==i) printf("%d\n",r[i]);
        else printf("%d\n",r[w[i]]);
    return 0;
}