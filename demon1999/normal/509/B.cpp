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
int main(){
    int n, m, j = 0;
    vector<pair<int, int> > a;
    cin >> n >> m;
    vector<int> ans[n];
    rs(a, n);
    forn(i, n){
 	ans[i].assign(m, 0);
        cin >> a[i].first;
	a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++){
        ans[a[0].second][i] = a[0].first / m;
        if (a[0].first % m > i)
          ans[a[0].second][i]++;
    }
    for (int i = 1; i < n; i++){
        int p = a[i].second;
	ans[p] = ans[a[i - 1].second];
	while(a[i].first > a[i - 1].first){
          if(j >= m){
            cout << "NO" << endl;
	    return 0;
	  }
	  ans[p][j]++; j++;
	  a[i - 1].first++;
	}
    }
    cout << "YES" << endl;
    forn(i, n){
        forn(k, m)
          forn(k2, ans[i][k]) cout << k + 1 << " ";
	cout << "\n";
    }
    return 0;
}