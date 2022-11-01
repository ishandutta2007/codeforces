#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define pb(a) push_back(a)
#define sz() size()
#define rs(n) resize(n)
#define mp(a, b) make_pair(a, b)
#define len() length()
#define re return
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
ll n, m, l12, r12, l11, r11;
struct st{
  ll l, r, n, t;
  st(ll l11, ll r11, ll n1, ll tr){
    l = l11, r = r11, n = n1, t = tr;
  }

};
vector<st> a;
vector<ll> b, ans;
set<pair<ll, ll> > r;
bool cmp(st a, st b){
  return (a.l < b.l)||(a.l == b.l && a.t < b.t);
}
int main(){
    //ifstream cin("input.txt");
    cin >> n >> m >> l12 >> r12;
    b.assign(n - 1, 0);
    forn(i, n - 1){
      cin >> l11 >> r11;
      a.push_back(st(l11 - r12, r11 - l12, i + 1, 0));
      l12 = l11, r12 = r11;
    }
    forn(i, m){
      cin >> l11;
      a.push_back(st(l11, l11, i + 1, 1));
    }
    sort(a.begin(), a.end(), cmp);
    for(ll i = 0; i < a.sz(); i++){
      //cout << a[i].l << " " << a[i].r << " " << a[i].n << " " << a[i].t << endl;
      if(a[i].t == 0){
        r.insert(mp(a[i].r, a[i].n - 1));
      }else{
        if(!r.empty()){
          if(r.begin() -> first < a[i].l){
            cout <<"No"; re 0;
          }
          b[r.begin() -> second] = a[i].n;
          r.erase(r.begin());
        }
      }
    }
    if(!r.empty()){
      cout <<"No"; re 0;
    }
    cout << "Yes\n";
    forn(i, n - 1)cout << b[i] << ' ';
    return 0;
}