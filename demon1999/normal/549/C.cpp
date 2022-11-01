#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k, k1, k2, a, st, den;
int main(){
    //ifstream cin("input.txt");
    cin >> n >> k;
    forn(i, n){
      cin >> a;
      if(a%2)k1++;
      else k2++;
    }
if(n == k){
 if(k1 % 2)cout << "Stannis";else cout << "Daenerys";return 0;
}
    den = (n - k)/2;
    st = n - k - den;
    if(den >= k1){
        cout << "Daenerys";
        return 0;
    }
    if(k2 == 0){
      if(k1 % 2)cout << "Stannis";else cout <<"Daenerys";
      return 0;
    }
    if(k % 2 == 0 && den >= k2){
      cout << "Daenerys"; re 0;
    }
    if(k % 2 == 1 && st >= k2){
       cout << "Stannis"; re 0;
    }
    if(k % 2 == 0){
        if(n % 2 == 1)cout << "Stannis";
        else cout << "Daenerys";
        re 0;
    }
    if(k % 2 == 1){
      if(n % 2 == 0)cout << "Stannis";
      else cout << "Daenerys";
    }
    return 0;
}