#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 400010
vector<int>e[SIZE],b[SIZE];
int ll[SIZE],rr[SIZE],son[SIZE],No,an[SIZE],now;
void dfs0(int x,int last){
    son[x]=1;
    ll[x]=No++;
    for(int i=0;i<e[x].size();i++){
        if(e[x][i]==last)continue;
        dfs0(e[x][i],x);
        son[x]+=son[e[x][i]];
    }
    rr[x]=No++;
}
int ac[SIZE<<1],ha[SIZE<<1];
void insert(int d[],int id,int L,int R,int L2,int R2,int v){
    if(L2<=L&&R<=R2){
        d[id]+=v;
        return;
    }
    int M=(L+R)>>1;
    if(R2<=M)insert(d,id<<1,L,M,L2,R2,v);
    else if(M<L2)insert(d,(id<<1)|1,M+1,R,L2,R2,v);
    else{
        insert(d,id<<1,L,M,L2,R2,v);
        insert(d,(id<<1)|1,M+1,R,L2,R2,v);
    }
}
int qq(int d[],int id,int L,int R,int x){
    if(L==x&&x==R){
        return d[id];
    }
    int M=(L+R)>>1;
    if(x<=M)return d[id]+qq(d,id<<1,L,M,x);
    else return d[id]+qq(d,(id<<1)|1,M+1,R,x);
}

int qq2(int d[],int id,int L,int R,int L2,int R2){
    if(L2<=L&&R<=R2){
        return d[id];
    }
    int M=(L+R)>>1;
    if(R2<=M)return qq2(d,id<<1,L,M,L2,R2);
    else if(M<L2)return qq2(d,(id<<1)|1,M+1,R,L2,R2);
    else return qq2(d,id<<1,L,M,L2,R2)+qq2(d,(id<<1)|1,M+1,R,L2,R2);
}
void insert2(int d[],int id,int L,int R,int x,int v){
    d[id]+=v;
    if(L==x&&x==R)return;
    int M=(L+R)>>1;
    if(x<=M)insert2(d,id<<1,L,M,x,v);
    else insert2(d,(id<<1)|1,M+1,R,x,v);
}
void dfs(int x,int last){
    vector<int>tmp,tmp2;
    int i;
    for(i=0;i<b[x].size();i++){
        if(qq(ac,1,1,No,ll[b[x][i]]))continue;
        else{
            tmp.pb(b[x][i]);
            insert(ac,1,1,No,ll[b[x][i]],rr[b[x][i]],1);
            int get_v=qq2(ha,1,1,No,ll[b[x][i]],rr[b[x][i]]);
            insert2(ha,1,1,No,ll[b[x][i]],son[b[x][i]]-get_v);
            tmp2.pb(son[b[x][i]]-get_v);
            now+=son[b[x][i]]-get_v;
        }
    }
    an[x]=now;
    for(int i=0;i<e[x].size();i++){
        if(e[x][i]==last)continue;
        dfs(e[x][i],x);
    }
    for(i=0;i<tmp.size();i++){
        insert(ac,1,1,No,ll[tmp[i]],rr[tmp[i]],-1);
        insert2(ha,1,1,No,ll[tmp[i]],-tmp2[i]);
        now-=tmp2[i];
    }
}
int main(){
    No=1;
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        b[x].pb(x);
        b[x].pb(y);
        b[y].pb(x);
        b[y].pb(y);
    }
    dfs0(1,0);
    dfs(1,0);
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%d",an[i]>0?(an[i]-1):0);
    }
    puts("");
    return 0;
}