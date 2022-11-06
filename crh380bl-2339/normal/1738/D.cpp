#include<bits/stdc++.h>
using namespace std;
int b[100005];
bool bo1[100005],bo2[100005];
vector<int>e[100005];
int siz[100005];
bool chk1(int n){
    int i;
    for(i=1;i<=n;++i)if(b[i]!=n+1)return 0;
    return 1;
}
bool chk2(int n){
    int i;
    for(i=1;i<=n;++i)if(b[i]!=0)return 0;
    return 1;
}
void DFS0(int x,int fa){
    int i;
    siz[x]=1;
    for(auto y:e[x]){
        DFS0(y,x);
        siz[x]+=siz[y];
    }
}
bool cmp(int x,int y){
    return siz[x]<siz[y];
}
int n;
void DFS1(int x){
    if(x>=1&&x<=n)printf("%d ",x);
    sort(e[x].begin(),e[x].end(),cmp);
    for(auto y:e[x]){
        DFS1(y);
    }
}
void work(){
    scanf("%d",&n);
    int i;
    siz[0]=siz[n+1]=0;
    e[0].clear();
    e[n+1].clear();
    for(i=1;i<=n;++i){
        scanf("%d",&b[i]);
        bo1[i]=bo2[i]=0;
        siz[i]=0;
        e[i].clear();
    }
    if(chk1(n)){
        printf("%d\n",n);
        for(i=1;i<=n;++i)printf("%d ",i);puts("");
        return;
    }
    if(chk2(n)){
        printf("0\n");
        for(i=1;i<=n;++i)printf("%d ",i);puts("");
        return;
    }
    int mx=2147483647;
    for(i=1;i<=n;++i){
        mx=min(mx,b[i]);
        if(mx>i){
            bo1[i]=1;
        }
    }
    mx=0;
    for(i=n;i>=1;--i){
        mx=max(mx,b[i]);
        if(mx<=i-1){
            bo2[i-1]=1;
        }
    }
    int k=-1;
    for(i=1;i<=n;++i){
        if(bo1[i]&&bo2[i]){
            k=i;
            break;
        }
    }
    printf("%d\n",k);
    for(i=1;i<=n;++i){
        e[b[i]].push_back(i);
    }
    if(e[0].size()){
        DFS0(0,-1);
        DFS1(0);
    }
    else{
        DFS0(n+1,-1);
        DFS1(n+1);
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}