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
ll n, m;
vector<pair<ll, ll> > a;
bool cmp(pair<ll, ll> a, pair<ll, ll> b){
  return a.second > b.second || (a.second == b.second && a.first < b.first);
}
int main(){
    cin >> n; rs(a, n);
    vector<ll> b[2], c[2];
    forn(i, n) cin >> a[i].first;
    forn(i, n) cin >> a[i].second;
    sort(a.begin(), a.end(), cmp);
    b[0].push_back(0);
    c[0].push_back(0);
    for(int j = 1; j <= n; j++){
        map<int, int> q;
        for(int i = 0; i < sz(b[0]); i++){
            if (q[b[0][i]] == 0){
              b[1].push_back(b[0][i]);
              c[1].push_back(c[0][i]);
              q[b[0][i]] = sz(b[1]);
            }
            else{
                c[1][q[b[0][i]] - 1] = min(c[1][q[b[0][i]] - 1], c[0][i]);
            }
            ll p = __gcd(b[0][i], a[j - 1].first);
            if(q[p] == 0){
                b[1].push_back(p);
                c[1].push_back(c[0][i] + a[j - 1].second);
                q[p] = sz(b[1]);
            }
            else{
                c[1][q[p] - 1] = min(c[1][q[p] - 1], c[0][i] + a[j - 1].second);
            }
        }
        if(j == n && q[1] == 0){
            cout << "-1"; return 0;
        }
        if(j == n){
            cout << c[1][q[1] - 1] << endl;
            return 0;
        }
        b[0] = b[1];
        c[0] = c[1];
       // for(int i = 0; i < sz(b[0]); i++) cout << b[0][i] << " ";
        //cout << endl;
        rs(b[1], 0);
        rs(c[1], 0);

    }

    return 0;
}