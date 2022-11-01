#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int mc[100001], nmc[100001], can[100001], p[100001];

int main () {
    scanf ("%d%d\n", &n, &m);
    int anmc = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &p[i]);
        if (p[i] > 0) {
            mc[p[i]]++; 
        } else {
            nmc[-p[i]]++;
            anmc++;
        }   
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (mc[i] + (anmc - nmc[i]) == m) {
            can[i] = 1;
            k++;
        }
    for (int i = 1; i <= n; i++) 
        if (p[i] > 0) { 
            if (can[p[i]] && k == 1) printf ("Truth\n"); else
            if (!can[p[i]]) printf ("Lie\n"); else printf ("Not defined\n");
        } else {
            if (!can[-p[i]]) printf ("Truth\n"); else
            if (can[-p[i]] && k == 1) printf ("Lie\n"); else printf ("Not defined\n");
        }
    return 0;
}