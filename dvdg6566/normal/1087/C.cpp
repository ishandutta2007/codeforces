#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vpi V;
int ans;
int x,y;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  V.resize(3);
  cin>>V[0].f>>V[0].s>>V[1].f>>V[1].s>>V[2].f>>V[2].s;
  ans = max({V[0].f, V[1].f, V[2].f}) - min({V[0].f, V[1].f, V[2].f}) + max({V[0].s, V[1].s, V[2].s}) - min({V[0].s, V[1].s, V[2].s});
  cout<<ans+1<<'\n';
  sort(ALL(V));
  x = V[0].f;
  y = V[0].s;
  cout<<x<<' '<<y<<'\n';
  while(1){
    if (x == V[1].f)break;
    ++x; 
    cout<<x<<' '<<y<<'\n';
  }
  while(1){
    if (y == V[1].s)break;
    if (y < V[1].s)++y;
    else --y;
    cout<<x<<' '<<y<<'\n'; 
  }
  x = V[1].f;
  if (V[2].s < min(V[0].s, V[1].s)){
    y = min(V[0].s, V[1].s);
  }else if (V[2].s > max(V[0].s, V[1].s)){
    y = max(V[0].s, V[1].s);
  }else y = V[2].s;
  // cout << "Testing " << x << ' ' << y << '\n';
   while(1){
    if (x == V[2].f)break;
    ++x; 
    cout<<x<<' '<<y<<'\n';
  }
  while(1){
    if (y == V[2].s)break;
    if (y < V[2].s)++y;
    else --y;
    cout<<x<<' '<<y<<'\n'; 
  }
}