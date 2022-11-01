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
int n;
vector<int> a;
int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
        while(a[i]%2 == 0) a[i]/=2;
        while(a[i]%3 == 0) a[i]/=3;
        if (i > 0 && a[i] != a[i - 1]) {
            cout << "No"; re 0;
        }
    }
    cout << "Yes";
    return 0;
}