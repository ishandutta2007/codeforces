#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define l1 l11
#define r1 r11
using namespace std;
typedef long long ll;
typedef long double ld;
const long ma11 = 524288, ma1 = 16;
int n, m, t, mm, hh, ss;
struct qq1{
  int t, b, nu;
};
bool ok = false;
vector<qq1> a;
bool cmp(qq1 a, qq1 b){
  return a.t < b.t || (a.t == b.t && a.b < b.b) || (a.t == b.t && a.b == b.b && a.nu < b.nu);
}
int main(){
    //freopen("i.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &t);
    forn(i, n){
        scanf("%d:%d:%d", &hh, &mm, &ss);
        qq1 p; p.t = hh * 3600 + 60 * mm + ss; p.nu = i;
        p.b = 1;
        a.push_back(p);
        p.b = -1;
        p.t += t;
        a.push_back(p);
    }
    sort(a.begin(), a.end(), cmp);
    map<int, int> k;
    deque<int> b;
    vector<int> ans(n, 0);
    int num = 1, bal = 0;
    for(int i = 0; i < 2 * n; i++){
         //cout << a[i].t << " " << a[i].b << " " << a[i].nu << endl;
        if(bal >= m)ok = true;
        if(a[i].b == -1){
          k[b.front()]--;
          if(k[b.front()] == 0)bal--;
          b.pop_front(); continue;
        }
        if(bal < m){
          b.push_back(num);ans[a[i].nu] = num; k[num]++; bal++;num++;
        }
        else {ans[a[i].nu] = b.back(); k[b.back()]++;b.push_back(b.back());}

    }
    if(!ok){
      cout << "No solution"; return 0;
    }
    cout << num - 1<< "\n";
    for(int i =0; i < n; i++)cout << ans[i] << "\n";
    return 0;
}