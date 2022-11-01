#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
//#include "grader.h"
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) (int)a.size()
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k;
vector<int> a;
int main(){
    //ifstream cin("input.txt");
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int pp = i;
        bool ok = true;
        for (int j = 2; j* j <= pp; j++) {
            if (pp % j == 0) ok = false;
        }
        if(ok) {
            while (pp <= n) {
                a.push_back(pp);
                pp *= i;
            }
        }
    }
    cout << (int)a.size() << "\n";
    forn (i, sz(a)) cout << a[i] << " ";
    return 0;
}