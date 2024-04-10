#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int n;
char a[111][111];

int main(){
#ifdef LOCAL
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;

  if (n == 1) cout << "1\no", exit(0);
  if (n == 2) cout << "-1", exit(0);

  int le = 0;
  while (le * le < n) ++le;

  for (int i = 0; i < le + 1; ++i) for (int j = 0; j < le + 1; ++j) a[i][j] = '.';

    int nn = n;
  for (int i = 0; i < le-1; ++i) for (int j = 0; j < le-1; ++j) a[i][j] = 'o', n--;

  for (int i = 0; i < le; ++i) {
    if (n == 0) break;
    if (n >= 2) {
      n -= 2;
      a[le - 1][i] = a[i][le - 1] = 'o';
    } else {
      a[le - 1][i] = a[i][le - 1] = 'o';
      if (i != le - 1)
      a[le - 2][le - 2] = '.';
      break;
    }
  }

  if (nn == le * le - 2) {
    ++le;
    a[0][le - 1] = a[le - 1][0] = 'o';
    a[le - 3][le - 2] = '.';
    a[le - 2][le - 3] = '.';
  }


  cout << le << endl;
  for (int i = le - 1; i >= 0; --i) {
    for (int j = 0; j < le; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }

}