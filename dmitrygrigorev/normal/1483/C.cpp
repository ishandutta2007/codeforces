#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<ll> rmq;

void upd(int i, int l, int r, int index, ll val) {
  if (r-l==1) {
    rmq[i] = val;
    return;
  }
  int mid = (l+r)/2;
  if (index < mid) upd(2*i+1, l, mid, index, val);
  else upd(2*i+2, mid, r, index, val);
  rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}

ll get(int i, int l, int r, int l1, int r1) {
  if (l1 >= r1) return -1e18;
  if (l == l1 && r==r1) return rmq[i];
  int mid = (l+r)/2;
  return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));

}


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  a.pb(n+1);
  b.pb(0);

  n++;

  rmq.assign(4*n, -1e18);
  vector<ll> dp;
  vector<ll> tree;

  dp.pb(b[0]);
  tree.pb(b[0]);
  upd(0, 0, n, 0, b[0]);

  vector<pair<int, int> > st;
  st.pb(mp(a[0], 0));

  for (int i = 1; i < n; ++i) {
    while (st.size() && st.back().x > a[i]) st.pop_back();

    int R = -1;
    if (st.size()) R = st.back().y;

    ll Z = get(0, 0, n, R+1, i);
    if (R!=-1) Z = max(Z, tree[R]);
    else Z = max(Z, 0LL);

    //cout << R << " " << i << " " << Z << " " << tree[R] << " " << Z+b[i] << endl;

    dp.pb(Z + b[i]);
    tree.pb(Z + b[i]);

    if (R!=-1) {
      tree.back() = max(tree.back(), tree[R]);
    }

   // cout << tree.back() << endl;

    upd(0, 0, n, i, dp[i]);

    st.pb(mp(a[i], i));

  }

  cout << dp.back();


}