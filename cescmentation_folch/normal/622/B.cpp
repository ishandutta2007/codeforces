#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int h, m;
  char mander;
  cin >> h >> mander >> m;
  int tt;
  cin >> tt;
  m += tt;
  h += m/60;
  h %= 24;
  m %= 60;
  if (h < 10) cout << 0;
  cout << h << ":";
  if (m < 10) cout << 0;
  cout << m << endl;
}