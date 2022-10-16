#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> pii;

const int inf = 2e9 + 100;

int brute(vector<pii> c, int w) {
	return 0;
	vector<long long> a(w + 3, inf);
	a[0] = 0;
	for (int i = 0; i < c.size(); ++i) {
		for (int j = w; j >= 0; --j) {
			a[j + 1] = min(a[j + 1], a[j] + c[i].first);
			a[j + 2] = min(a[j + 2], a[j] + c[i].second + c[i].first);
		}
	}
	return a[w];
}

int solve() {
    int n, w; if (!(cin >> n >> w)) return false;
	vector<pii> c(n); for (int i = 0; i < n; ++i) { cin >> c[i].first >> c[i].second; c[i].second -= c[i].first; }
    
    set<pii> one;
    set<pii> two;
    
    for (int i = 0; i < n; ++i) {
        one.insert(pii(c[i].first, i));
        two.insert(pii(c[i].first + c[i].second, i));
    }
    
    vector<int> res(n);
    long long cost = 0;
    
    set<pii> have;
    
    for (int i = 0; i < w; ++i) {
        int cost_add_1 = inf;
        if (one.size()) {
            cost_add_1 = one.begin()->first;
        }
        
        int cost_chd_1 = inf;
        if (two.size() && have.size()) {
            cost_chd_1 = two.begin()->first - have.rbegin()->first;
        }
        
        if (cost_add_1 < cost_chd_1) {
            int id = one.begin()->second;
            
            if (res[id] == 0) {
                two.erase(pii(c[id].first + c[id].second, id));
                one.erase(pii(c[id].first, id));

                cost += cost_add_1;
                res[id] = 1;
                
                have.insert(pii(c[id].first, id));
                one.insert(pii(c[id].second, id));
            } else {
                one.erase(pii(c[id].second, id));
                have.erase(pii(c[id].first, id));
                
                cost += cost_add_1;
                res[id] = 2;
                
                have.insert(pii(c[id].second, id));
            }            
        } else {
            int id_add = two.begin()->second;
            int id_del = have.rbegin()->second;
            
            cost += cost_chd_1;
            
            if (res[id_add] == 0) {
                two.erase(pii(c[id_add].first + c[id_add].second, id_add));
				one.erase(pii(c[id_add].first, id_add));
                
                res[id_add] = 2;
                
                have.insert(pii(c[id_add].second, id_add));
            }
            
            if (res[id_del] == 1) {
                one.erase(pii(c[id_del].second, id_del));
                have.erase(pii(c[id_del].first, id_del));
                
                res[id_del] = 0;
                
				one.insert(pii(c[id_del].first, id_del));
                two.insert(pii(c[id_del].first + c[id_del].second, id_del));
            } else {
                have.erase(pii(c[id_del].second, id_del));
                
                res[id_del] = 1;
                have.insert(pii(c[id_del].first, id_del));
                one.insert(pii(c[id_del].second, id_del));
            }
        }
    }
/*    
    if (cost != brute(c, w)) {
		int b = brute(c, w);
		int x = 1;
	}
	assert(cost == brute(c, w));
*/
    cout << cost << endl;
    for (int i = 0; i < n; ++i) cout << res[i];
    cout << endl;

	return true;
}

int main() {
    while (solve());
    return 0;
}