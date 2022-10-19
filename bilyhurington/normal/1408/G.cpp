/*
 * @Author: BilyHurington
 * @Date: 2021-06-30 09:49:24
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-06-30 11:16:59
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,m,bcj[3010],N,siz[3010],cnt[3010];
int find(int x){return x==bcj[x]?x:bcj[x]=find(bcj[x]);}
struct edge{int x,y,v;}e[1500010];
bool operator < (edge A,edge B){return A.v<B.v;}
vector<int> T[3010];int dfn_tot;
vector<int> pos[3010];
void dfs(int x){
    // printf("NODE: %d\n",x);
    int l=dfn_tot+1;
    if(!T[x].size()) dfn_tot++;
    for(auto to:T[x]) dfs(to);
    if(siz[x]*(siz[x]-1)/2==cnt[x]){
        pos[l].push_back(dfn_tot);
        // printf("%d %d\n",l,dfn_tot);
    }
}
const int mod=998244353;
int f[1510][1510];
void Add(int &x,int y){x+=y;x-=x>=mod?mod:0;}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&n);N=n;
    for(int i=1,x;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&x);
            if(i<j) e[++m]=edge{i,j,x};
        }
    }
    for(int i=1;i<=2*n;i++) bcj[i]=i;
    for(int i=1;i<=n;i++) siz[i]=1;
    sort(e+1,e+m+1);
    for(int ti=1;ti<=m;ti++){
        int x=e[ti].x,y=e[ti].y;
        if(find(x)==find(y)){
            cnt[find(x)]++;
            continue;
        }N++;
        siz[N]=siz[find(x)]+siz[find(y)];
        cnt[N]=cnt[find(x)]+cnt[find(y)]+1;
        T[N].push_back(find(x));
        T[N].push_back(find(y));
        bcj[find(x)]=bcj[find(y)]=N;
    }
    dfs(N);f[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            for(auto k:pos[i+1]){
                Add(f[k][j+1],f[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",f[n][i]);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}