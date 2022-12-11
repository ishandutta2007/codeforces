#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL long long
using namespace std;
const int N=2e5+50,mod=1e9+7,inv2=5e8+4;
const int M=1e5;
int T,n,b[N],q[N],l,r,kl,kr;
vector<int>v[N],ans;
void solve(){
  scanf("%d",&n);
  for(int i=0;i<=n+1;i++)v[i].clear();
  ans.clear();r=0;
  kl=0;kr=n+1;
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]),v[b[i]].pb(i);
    if(b[i]<i)kr=min(kr,i),kl=max(kl,b[i]);
    else kr=min(kr,b[i]),kl=max(kl,i);
  }
  l=1;q[++r]=0;q[++r]=n+1;
  while(l<=r){
    int x=q[l++];
    if(!v[x].size())ans.pb(x);
    else{
      if(l>r){
        ans.pb(x);
        for(int i=0;i<v[x].size();i++)
          q[++r]=v[x][i];
      }
      else q[++r]=x;
    }
  }
  printf("%d\n",kl);
  for(int i=2;i<ans.size();i++)
    printf("%d ",ans[i]);
  puts("");
}
int main(){
  // freopen("in.txt","r",stdin);
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}