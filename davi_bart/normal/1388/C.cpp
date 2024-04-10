#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> p(100010),h(100010),dim(100010);
vector<int> v[100010];
bool ans=1;
int dfs(int pos,int prec){
  dim[pos]=p[pos];
  for(int x:v[pos])if(x!=prec)dim[pos]+=dfs(x,pos);
  return dim[pos];
}
int k(int pos,int prec){
  int aa=dim[pos]-(dim[pos]-h[pos])/2,bb=(dim[pos]-h[pos])/2;
  if(aa-bb!=h[pos] || aa<0 || bb<0)ans=0;
  int u=0;
  int z=0;
  for(int y:v[pos]){
      if(y!=prec){
          u+=k(y,pos);
          z+=h[y];
      }
  }
  /*int cur=h[pos]-z;
  int aaa=p[pos]-(p[pos]-cur)/2,bbb=(p[pos]-cur)/2;
  if(u+aaa>aa || aaa<0 || bbb<0)ans=0;*/
  if(u>aa)ans=0;
  return aa;
}
void solve(){
  ans=1;
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>p[i];
    v[i].clear();
    dim[i]=0;
  }
  for(int i=0;i<N;i++){
    cin>>h[i];
  }
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
  }
  dfs(0,-1);
  k(0,-1);
  if(M-(M-h[0])/2-(M-h[0])/2!=h[0])ans=0;
  if(ans)cout<<"YES\n";
  else cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)solve();
}