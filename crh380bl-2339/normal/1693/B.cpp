#include<bits/stdc++.h>
using namespace std;
#define N 200005
vector<int>e[N];
int L[N],R[N];
int ans;
int DFS(int x){
    long long sum=0;
    for(auto y:e[x]){
        sum+=DFS(y);
    }
    if(sum>=L[x])return min(1LL*R[x],sum);
    else{
        ++ans;
        return R[x];
    }
}
int main(){
    int t,n,i,j;
    cin>>t;
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i)e[i].clear();
        for(i=2;i<=n;++i){
            scanf("%d",&j);
            e[j].push_back(i);
        }
        for(i=1;i<=n;++i)scanf("%d%d",&L[i],&R[i]);
        DFS(1);
        printf("%d\n",ans);
    }
    return 0;
}