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
typedef vector<int> vi;
int n, k, p, cow, mi;
vector<int> a[100000];
int main(){
    cin >> n >> k;
    //cout << n << " " << k << endl;
    cow = n - k;
    mi = 1;
    for(int i = 0; i < k; i++){
      cin >> p;
      a[i].rs(p);
      forn(j, p)cin >> a[i][j];
      forn(j, p){
        if(a[i][j] != j + 1)break;
        mi = j + 1;
      }
    }
    cout << n - mi + max(n - k - mi + 1, 0);
    return 0;
}