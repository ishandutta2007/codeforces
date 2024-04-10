#include<bits/stdc++.h>
using namespace std;
vector<int>e[200005];
int s[200005];
set<int>S[200005];
map<int,long long> Ans[200005];
long long DFS(int x,int k){
    if(S[x].find(k)!=S[x].end())return Ans[x][k];
    long long ans=1LL*k*s[x];
    if(e[x].size()==0)return Ans[x][k]=ans;
    S[x].insert(k);
    int val=k/e[x].size(),rem=k%e[x].size();
    vector<int>tmp;
    tmp.clear();
    for(auto y:e[x]){
        ans+=1LL*DFS(y, val);
        if(rem)tmp.push_back(DFS(y, val+1)-DFS(y,val));
        else tmp.push_back(0);
    }
    sort(tmp.begin(), tmp.end());
    for(int i=e[x].size()-1;i>=e[x].size()-rem;--i)ans=ans+tmp[i];
    return Ans[x][k]=ans;
}
void work(){
    int n,m;
    scanf("%d%d",&n,&m);
    int i,p;
    for(i=1;i<=n;++i){
        e[i].clear();
        S[i].clear();

    }
    for(i=2;i<=n;++i){
        scanf("%d",&p);
        e[p].push_back(i);
    }
    for(i=1;i<=n;++i)scanf("%d",&s[i]);
    printf("%lld\n",DFS(1,m));
    //printf("%lld\n",DFS(5,2,0));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}