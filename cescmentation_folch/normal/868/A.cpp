#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

int A[26];
int B[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string res;
  cin >> res;
  int k1 = res[0] - 'a';
  int k2 = res[1] - 'a';
  int n;
  cin >> n;
  while (n--) {
    char a, b;
    cin >> a >> b;
    A[a - 'a'] = 1;
    B[b - 'a'] = 1;
    if (res[0] == a and res[1] == b) {
      cout << "YES" << endl;
      return 0;
    }
  }
  if ((A[k2] and B[k1])) cout << "YES" << endl;
  else cout << "NO" << endl;
}