#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re return
typedef long long ll;
typedef long double ld;
using namespace std;
ld ans = 0, p, p1 = 0;
ll a[100], r[100], k;
int n;
ld func(ll p1){
  ld ans = 0;
  if(p1 == k){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          if(i < j && a[i] > a[j])ans++;
    p++;
    return ans;
  }
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++){
        for(int k1 = i; k1 <= j; k1++)r[k1] = a[i + j - k1];
        for(int k1 = i; k1 <= j; k1++)a[k1] = r[k1];
        ans += func(p1+1);
        for(int k1 = i; k1 <= j; k1++)r[k1] = a[i + j - k1];
        for(int k1 = i; k1 <= j; k1++)a[k1] = r[k1];
    }
  return ans;
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i];
    cout.precision(30);
    cout << func(0) / p;
    return 0;
}