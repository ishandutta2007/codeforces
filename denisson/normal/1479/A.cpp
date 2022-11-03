#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
  int n;
  cin >> n;

/*
  if (n <= 50) {
    int last = 1e9;
    for (int i = 0; i < n; ++i) {
      cout << "? " << i + 1 << endl;
      int x; cin >> x;
      if (last < x) {
        cout << "! " << i + 1 << endl;
        exit(0);
      }
    }
    cout << "! " << n << endl;
    exit(0);
  }  
*/


  int vl = -1, vr = n - 1;
  while (vl + 1 < vr) { 
    int vm = (vl + vr) >> 1;
    cout << "? " << vm + 1 << endl;
    int x1; cin >> x1;
    cout << "? " << vm + 2 << endl;
    int x2; cin >> x2;
    if (x1 > x2) vl = vm; else vr = vm;
  }

  cout << "! " << vr + 1 << endl;
}