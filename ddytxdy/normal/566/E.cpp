#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1010;
int n,m,fl[N];
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
bitset<N>b[N],p,c[N],is,q;
vector<int>v[N];
int main(){
    // p.set(1);p.set(2);
    // cout<<p._Find_next(2);
    n=read();
    if(n==2)puts("1 2"),exit(0);
    for(int i=1,k;i<=n;i++)
        for(k=read(),k==n&&++m;k--;)
            b[i].set(read());
    if(m==n){
        for(int i=2;i<=n;i++)printf("1 %d\n",i);exit(0);
    }
    if(m==2){
        p.set();for(int i=1;i<=n;i++)p&=b[i];
        int x=p._Find_first(),y=p._Find_next(x);
        printf("%d %d\n",x,y);
        for(int i=1;i<=n;i++)if(b[i].count()!=n){p=b[i];break;}
        for(int i=1;i<=n;i++)if(i!=x&&i!=y)
            printf("%d %d\n",i,p[i]?x:y);
        exit(0);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            p=b[i]&b[j];
            if(p.count()!=2)continue;
            int x=p._Find_first(),y=p._Find_next(x);
            if(c[x][y])continue;
            c[x].set(y);c[y].set(x);fl[x]=fl[y]=1;
            v[x].pb(y);
        }
    for(int i=1;i<=n;i++)
        if(fl[i])is.set(i),c[i].set(i);
    for(int i=1;i<=n;i++)if(fl[i]==0){
        int mn=1e9;
        for(int j=1;j<=n;j++)if(b[j][i]&&b[j].count()<mn)mn=b[j].count(),p=b[j];
        q=p&is;
        for(int j=1;j<=n;j++)if(fl[j]==1){
            q=p&is;if(q!=c[j])continue;
            q=q^p;
            for(int k=q._Find_first();k<=n;k=q._Find_next(k))
                v[j].pb(k),fl[k]=2;
            fl[j]=2;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<v[i].size();j++)
            printf("%d %d\n",i,v[i][j]);
    return 0;
}