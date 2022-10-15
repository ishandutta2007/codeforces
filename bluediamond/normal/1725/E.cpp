#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M=998244353;
const int FACTN=200000+7;
int add(int a,int b){
  a+=b;
  if(a>=M)return a-M;
  if(a<0)return a+M;
  return a;
}
int mul(int a,int b){
  return a*(ll)b%M;
}
int add(int a,int b,int c){
  return add(add(a,b),c);
}
int mul(int a,int b,int c){
  return mul(mul(a,b),c);
}
int add(int a,int b,int c,int d){
  return add(add(a,b,c),d);
}
int mul(int a,int b,int c,int d){
  return mul(mul(a,b,c),d);
}
int add(int a,int b,int c,int d,int e){
  return add(add(a,b,c,d),e);
}
int mul(int a,int b,int c,int d,int e){
  return mul(mul(a,b,c,d),e);
}
int add(int a,int b,int c,int d,int e,int f){
  return add(add(a,b,c,d,e),f);
}
int mul(int a,int b,int c,int d,int e,int f){
  return mul(mul(a,b,c,d,e),f);
}
int add(int a,int b,int c,int d,int e,int f,int g){
  return add(add(a,b,c,d,e,f),g);
}
int mul(int a,int b,int c,int d,int e,int f,int g){
  return mul(mul(a,b,c,d,e,f),g);
}
int add(int a,int b,int c,int d,int e,int f,int g,int h){
  return add(add(a,b,c,d,e,f,g),h);
}
int mul(int a,int b,int c,int d,int e,int f,int g,int h){
  return mul(mul(a,b,c,d,e,f,g),h);
}
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=mul(r,a);
    a=mul(a,a);
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return mul(a,pw(b,M-2));
}
void addup(int &a,int b){
  a=add(a,b);
}
void mulup(int &a,int b){
  a=mul(a,b);
}
void dvup(int &a,int b){
  a=dv(a,b);
}
int fact[FACTN],ifact[FACTN];
void computeFACT(){
  fact[0]=1;
  for(int i=1;i<FACTN;i++)fact[i]=mul(fact[i-1],i);
  ifact[FACTN-1]=dv(1,fact[FACTN-1]);
  for(int i=FACTN-2;i>=0;i--)ifact[i]=mul(ifact[i+1],i+1);
}
int comb(int n, int k) {
  assert(0 <= k && k <= n && n < FACTN);
  return mul(fact[n],mul(ifact[k],ifact[n-k]));
}

const int N = (int) 2e5 + 7;
const int K = 20;
int total_print = 0, rl_sub[N], par_virtual[N];
vector<int> g_virtual[N];
vector<int> prime_dvs[N];
int n, g3[N], par[N], vl[N];
bool isp[N];
vector<int> g[N];
vector<int> where[N];
int dep[N];
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
pair<int, int> tab_lca[2 * N][K];


void dfs_lca(int a, int p = -1)
{
    euler_tour[++tour_sz] = a;
    first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
    for (auto &b : g[a])
    {
        if (b == p) continue;
        dep[b] = 1 + dep[a];
        dfs_lca(b, a);
        euler_tour[++tour_sz] = a;
        last_time_on_tour[a] = tour_sz;
    }
}

void lcaTM()
{
    dfs_lca(1);
    for (int i = 2; i <= tour_sz; i++)
    {
        lg2[i] = 1 + lg2[i / 2];
    }
    for (int i = 1; i <= tour_sz; i++)
    {
        tab_lca[i][0] = {dep[euler_tour[i]], euler_tour[i]};
    }
    for (int k = 1; (1 << k) <= tour_sz; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++)
        {
            tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int lca(int a, int b)
{
    if (first_time_on_tour[a] > last_time_on_tour[b])
    {
        swap(a, b);
    }
    a = first_time_on_tour[a];
    b = last_time_on_tour[b];
    int k = lg2[b - a + 1];
    return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}


void build_tree(int a, int p = 0) {
  rl_sub[a] = 1;
  par[a] = p;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) continue;
    kids.push_back(b);
    build_tree(b, a);
    rl_sub[a] += rl_sub[b];
  }
  g[a] = kids;
}

bool is[N];
int sub[N];
int sub2[N];
int ttl;

void dfs(int a) {
  sub[a] = is[a];
  for (auto &b : g[a]) {
    dfs(b);
    sub[a] += sub[b];
  }
}

int f(int x) {
  return add(g3[ttl], -add(g3[x], g3[ttl - x]));
}

void solve(int a) {
  addup(total_print, f(sub[a]));
  for (auto &b : g[a]) {
    solve(b);
  }
}

bool cmp(int i, int j) {
  return first_time_on_tour[i] < first_time_on_tour[j];
}

void dfs_virtual(int a) {
  sub2[a] = is[a];
  for (auto &b : g_virtual[a]) {
    dfs_virtual(b);
    sub2[a] += sub2[b];
  }
  if (is[a]) {
    assert(sub2[a] >= 1);
  }
  if (a == 1) {
    addup(total_print, f(sub2[a]));
  } else {
    addup(total_print, mul(dep[a] - dep[par_virtual[a]], f(sub2[a])));
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  computeFACT();

  for (int i = 3; i < N; i++) {
    g3[i] = comb(i, 3);
  }

  isp[2] = 1;
  for (int i = 3; i < N; i += 2) {
    isp[i] = 1;
  }
  for (int i = 3; i * i < N; i += 2) {
    if (isp[i]) {
      for (int j = i * i; j < N; j += 2 * i) {
        isp[j] = 0;
      }
    }
  }

  if (0) { /// testing time
    int cnt = 0;
    for (int i = 1; i <= 100; i++) {
      if (isp[i]) {
        cnt++;
        cout << cnt << " : " << i << "\n";
      }
    }
    exit(0);
  }

  for (int p = 1; p < N; p++) {
    if (isp[p]) {
      for (int i = p; i < N; i += p) {
        prime_dvs[i].push_back(p);
      }
    }
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> vl[i];
    for (auto &p : prime_dvs[vl[i]]) {
      where[p].push_back(i);
    }
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  build_tree(1);
  lcaTM();
  for (int p = N - 1; p >= 1; p--) {
    ttl = (int) where[p].size();

   /// p = 3;
  ///  p = 7;
    if (!isp[p]) continue;
    if (where[p].empty()) continue;


    vector<int> verts;
    verts.push_back(1);
    for (auto &i : where[p]) {
      is[i] = 1;
      verts.push_back(i);
    }

    sort(verts.begin(), verts.end(), cmp);

    if (1) {
      vector<int> verts2 = verts;
      for (int j = 1; j < (int) verts.size(); j++) {
        verts2.push_back(lca(verts[j - 1], verts[j]));
      }
      sort(verts2.begin(), verts2.end(), cmp);
      assert(!verts2.empty());
      verts = {verts2[0]};
      for (int i = 1; i < (int) verts2.size(); i++) {
        if (verts2[i - 1] != verts2[i]) {
          verts.push_back(verts2[i]);
        }
      }
    }


    vector<int> stk;

    for (auto &v : verts) {
      while (1) {
        if (stk.empty()) {
          assert(v == 1);
          stk.push_back(v);
          break;
        }
        assert(!stk.empty());
        if (lca(v, stk.back()) != stk.back()) {
          stk.pop_back();
          continue;
        }
        par_virtual[v] = stk.back();
        g_virtual[stk.back()].push_back(v);
        stk.push_back(v);
        break;
      }
    }
    dfs_virtual(1);
    for (auto &v : verts) {
      g_virtual[v].clear();
      is[v] = 0;
      sub[v] = 0;
    }
  }
  cout << total_print << "\n";
  return 0;
}