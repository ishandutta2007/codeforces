#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void removen(tint i, vvi &grafo, vi &ind, vi &removed) {
    if(removed[i]) return;
    removed[i] = 1;
    for(auto j: grafo[i]) {
        ind[j]--;
        if(ind[j] == 0) {
            removen(j, grafo, ind, removed);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T;
	forn(tc, T) {
        int n;
        cin >> n;
        vi a(n);
        vi b(n);
        map<tint, tint> apps;
        map<tint, tint> firstapp;
        forn(i, n) {
            cin >> a[i];
            if(apps[a[i]] == 0) {
                firstapp[a[i]] = i;
            }
            apps[a[i]]++;
        }
        tint mode = 0, amode = 0;
        for(auto &tup: apps) {
            if(tup.second > amode) {
                mode = tup.first;
                amode = tup.second;
            }
        }

        vvi grafo(n);

        vi ind(n);
        forn(i, n) {
            cin >> b[i];
            if(a[i] != mode && b[i] != mode) {
                grafo[firstapp[a[i]]].push_back(firstapp[b[i]]);
                ind[firstapp[b[i]]]++;
            }
        }

        vi removed(n);
        forn(i, n) {
            if(!removed[i] && ind[i] == 0) {
                removen(i, grafo, ind, removed);
            }
        }

        tint cycle = 0;
        forn(i, n) if(!removed[i]) cycle = 1;
        if(cycle) {
            cout << "WA" << endl;
        } else {
            cout << "AC" << endl;
        }
    }
}