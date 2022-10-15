#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int p[300100], depth[300100], heavy[300100], head[300100], pos[300100], rpos[300100];
vi adjList[300100];
int N,M,a,b;
int cur;

int fw[300100];
void update(int x, int y, int v) { // incluse
	x--;
	for(; y; y-=y&(-y)) fw[y] += v;
	for(; x; x-=x&(-x)) fw[x] -= v;
}

int query(int x) {
    if(x==0)return INF;
    int res = 0;
    for (; x<=N; x+=x&(-x)) res += fw[x];
    return res;
}

int dfs(int x){
  int size = 1;
  int mchild = 0;
  for (auto i : adjList[x]){
    if (i == p[x])continue;
    p[i] = x;
    depth[i] = depth[x] + 1;
    int cs = dfs(i);
    size += cs;
    if (cs > mchild){
      mchild = cs;
      heavy[x] = i;
    }
  }
  return size;
}

void decompose(int x, int h){
  head[x] = h; pos[x] = cur++;
  if (heavy[x] != -1)decompose(heavy[x], h);
  for (auto i : adjList[x]){
    if (i == p[x])continue;
    if (i == heavy[x])continue;
    decompose(i,i);
  }
}

int wgt, ans, curtop, lows, prevtop, lastadded;

int find_top(int x){
  // for (int i=1;i<=N;++i)cout<<query(i)<<' ';cout<<'\n';
  for (;x;x=p[head[x]]){
    // cout << "CURRENT "  << x << ' ' << query(pos[p[head[x]]]) << '\n';
    if (query(pos[head[x]]) != lows){
      if (query(pos[p[head[x]]]) == lows){
        return p[head[x]];
      }
      continue;
    } 
    int low = pos[head[x]];
    int upp = pos[x];
    // cout<<low<<' '<<upp<<'\n';
    while(upp-low > 1){
      int mid = (low+upp)/2;
      if (query(mid) == lows)low = mid;
      else upp = mid;
    }
    if (query(upp) != lows)upp = low;
    // cout << "Query " << upp << '\n';
    return rpos[upp];
  }
  return -INF;
}

void add(int x){
  ++lows;
  lastadded = x;
  if (!query(pos[x])){
    for (int y=x;y;y=p[head[y]]){
      if(!query(pos[head[y]])){
        wgt += (pos[y] - pos[head[y]] + 1);
        if (query(pos[p[head[y]]])){
          break;
        }
        continue;
      }
      int low = pos[head[y]];
      int upp = pos[y];
      // cout << low << ' ' << upp << '\n';
      // for (int i=1;i<=N;++i)cout<<query(i)<<' ';cout<<'\n';
      while(upp-low > 1){
        int mid = (low+upp)/2;
        if (query(mid))low = mid;
        else upp = mid;
      }
      if (query(upp))upp = low;
      wgt += (pos[y] - upp + 1);
      // cout << "Stop adding at " << upp << '\n';
      break;
    }
  }
  // cout << "Weight is now " << wgt << '\n';
  for(int y=x;y;y=p[head[y]]){
    // cout<<x<<'\n';
    update(pos[head[y]], pos[y], 1);
    // cout << "Increase " << pos[head[y]] << ' ' << pos[y] << '\n';
  }
  int top = find_top(x);
  wgt += (depth[prevtop] - depth[top]);
  prevtop = top;
  // cout << wgt << '\n';
}

void remove(int x){
  --lows;
  for(int y=x;y;y=p[head[y]]){
    update(pos[head[y]], pos[y], -1);
    // cout << "Decrease " << pos[head[y]] << ' ' << pos[y] << '\n';
  }
  if (query(pos[x]) == 0)for (int y=x;y;y=p[head[y]]){
    if(!query(pos[head[y]])){
      wgt -= (pos[y] - pos[head[y]] + 1);
      // cout<<"GG\n";
      // cout << "REMOVE " << (pos[y] - pos[head[y]] + 1) << '\n';
      if (query(pos[p[head[y]]])){
        break;
      }
      continue;
    }
    int low = pos[head[y]];
    int upp = pos[y];
    // cout<<low<<' '<<upp<<'\n';
    while(upp-low > 1){
      int mid = (low+upp)/2;
      if (query(mid))low = mid;
      else upp = mid;
    }
    if (query(upp))upp = low;
    wgt -= (pos[y] - upp + 1);
    // cout << "Stop adding at " << upp << '(' << y << ')' << '\n';
    // cout << "REMOVE " << pos[y] - upp + 1<< '\n';
    break;
  }
  int top = find_top(lastadded);
  // cout << "TOP " << top <<' ' << depth[top]<< ' ' << depth[prevtop] << '\n';
  wgt += (depth[prevtop] - depth[top]);
  prevtop = top;
  // cout << wgt << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>M;
  for (int i=0;i<N-1;++i){
    cin>>a>>b;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  memset(heavy,-1,sizeof(heavy));
  cur = 1;
  dfs(1);
  decompose(1,1);
  int startind = 1;
  for (int i=1;i<=N;++i)rpos[pos[i]] = i;
  // add(2); // Weight 1
  // add(3); // Weight 7
  // add(5); // Weight 10
  // remove(3); // Weight 10
  // add(4); // Weight 10
  // remove(5); // Weight 4
  // add(3);
  // add(6);
  // add(4);
  // remove(4);
  for (int i=1;i<=N;++i){
    add(i);
    // cout<<"Added " << i << " weight is now " << wgt << '\n';
    while(wgt > M){
      remove(startind);
      // cout << "Removed " << startind << " weight is now " << wgt << '\n';
      ++startind;
    }
    ans = max(ans, i-startind+1);
  }
  cout<<ans;
}