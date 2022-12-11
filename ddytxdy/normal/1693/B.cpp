#include<cmath>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N=2e5+50;
int T,ans,n,a[N],b[N],l[N],r[N];
vector<int>v[N];
void dfs(int x){
  if(!v[x].size()){b[x]=r[x];ans++;return;}
  LL sum=0;
  for(int i=0,y;i<v[x].size();i++){
    dfs(y=v[x][i]);
    sum+=b[y];
  }
  if(sum>=l[x])b[x]=min(sum,1ll*r[x]);
  else b[x]=r[x],ans++;
}
void solve(){
  scanf("%d",&n);ans=0;
  for(int i=1;i<=n;i++)v[i].clear();
  for(int i=2,x;i<=n;i++)
    scanf("%d",&x),v[x].pb(i);
  for(int i=1;i<=n;i++)
    scanf("%d%d",&l[i],&r[i]);
  dfs(1);
  printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}