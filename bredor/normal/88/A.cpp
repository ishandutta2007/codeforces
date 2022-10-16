//  228

// Problem: A. Chord
// Contest: Codeforces - Codeforces Beta Round #73 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/88/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

// Handle: Scortier (Aditya Singh Sisodiya)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define test \
  int tt;    \
  cin >> tt; \
  while (tt--)
#define int long long int
#define fl(i, a, b) for (int i = a; i < b; i++)
#define bfl(i, a, b) for (int i = b - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1.0)
#define assign(x, val) memset(x, val, sizeof(x))
#define prec(val, dig) fixed << setprecision(dig) << val
#define pi pair<int, int>
#define pr(gg) cout << gg << endl
#define mk(arr, n, type) type *arr = new type[n];
#define e endl
void scortier() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
/**********=============########################============***********/
string h[3];
map<string, int> id;

string fuck[12] = {"C",  "C#", "D",  "D#", "E", "F",
                   "F#", "G",  "G#", "A",  "B", "H"};

//{x,x+3,x+7}mod12 minor ones
// major one  {x, x +4, x +7}.
void solve() {
  for (int i = 0; i < 12; i++) id[fuck[i]] = i;
  while (cin >> h[0] >> h[1] >> h[2]) {
    int t[3];
    for (int i = 0; i < 3; i++) t[i] = id[h[i]];
    sort(t, t + 3);
    int ans = 0;
    for (int i = 0; ans == 0 && i < 3; i++) {
      int d1 = (t[(i + 1) % 3] - t[i] + 12) % 12;
      int d2 = (t[(i + 2) % 3] - t[(i + 1) % 3] + 12) % 12;
      if (d1 == 4 && d2 == 3)
        ans = 1;
      else if (d1 == 3 && d2 == 4)
        ans = 2;
    }
    if (ans == 0)
      pr("strange");
    else if (ans == 1)
      pr("major");
    else
      pr("minor");
  }
}

int32_t main() {
  scortier();
  solve();
  return 0;
}