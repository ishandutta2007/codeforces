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
int n, k, k1, k2, st, den;
vector<pair<int, int> > a;
bool cmp(pair<int, int> a, pair<int, int> b){
  return a.first - (n - a.second - 1) < b.first - (n - b.second - 1);
}
int main(){
    cin >> n;a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;a[i].second = i;
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++){
        a[i].first += a[i].second - i;
        if(i > 0 && a[i].first < a[i - 1].first){
            cout << ":("; return 0;
        }
    }
    forn(i, n)cout << a[i].first << " ";
    return 0;
}