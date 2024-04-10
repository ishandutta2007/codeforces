//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  short a,b,c;
  cin >> a >> b >> c;
  short ans = min({max(a,b),max(b,c),max(a,c)});
  cout << abs(a - ans) + abs(b - ans) + abs(c - ans);
}