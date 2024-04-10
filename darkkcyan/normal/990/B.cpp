#include<bits/stdc++.h>
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
using namespace std;

#define maxn 201010
int n, k;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep(i, n) {
    cin >> a[i];
  }
  sort(a, a + n);
  vector<int> st;
  rep(i, n) {
    while (len(st) and a[i] > st.back() and a[i] <= st.back() + k) st.pop_back();
    st.push_back(a[i]);
  }
  cout << len(st);

  return 0;
}