#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < (n); )
#define rep1(i,n) for (int i = 0; i ++ < (n); )
#define len(x) ((int)x.size())
#define lamb(args, ret) [&]args {return ret;}

template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxn 1010
int n, s;
bool a[maxn], b[maxn];

int main(void ){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> s;
  int u;
  rep1(i, n) {
    cin >>u;
    a[i] = u == 1;
  }

  rep1(i, n) {
    cin >> u;
    b[i] = u == 1;
  }

  if (s == 1) {
    puts("YES");
    return 0;
  }

  if (!a[1]) {
    puts("NO");
    return 0;
  }

  if (a[s]) {
    puts("YES");
    return 0;
  }

  if (!b[s]) {
    puts("NO");
    return 0;
  }

  for (int i = s + 1; i <= n; ++i) {
    if (a[i] and b[i]) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");

  return 0;
}