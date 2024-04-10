#include <bits/stdc++.h>
using namespace std;
#define int long long

// Interval Container. Source : KACTL
// Add and remove intervals from a set of disjoint intervals.
// Will merge the added interval with any overlapping intervals in the set when adding.
// Intervals are [inclusive, exclusive).
// Time: O(log N)
typedef pair<int, int> pii;
set<pii>::iterator addInterval(set<pii>& is, int L, int R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		is.erase(it);
	}
	return is.insert(before, {L,R});
}
void removeInterval(set<pii>& is, int L, int R) {
	if (L == R) return;
	auto it = addInterval(is, L, R);
	auto r2 = it->second;
	if (it->first == L) is.erase(it);
	else (int&)it->second = L;
	if (R != r2) is.emplace(R, r2);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<pair<char, int>> query(n);
    for(int i = 0; i < n; i++) {
        cin >> query[i].first >> query[i].second;
    }
    set <int> s; // all distinct added values
    set <int> k; // all distinct k-mex queries
    for(auto q : query) {
        if(q.first == '+') s.insert(q.second);
        if(q.first == '?') k.insert(q.second);
    }
    map<int, vector<int>> pos; // pos[value] = set of k queries where it might be possible as an answer.
    for(auto i : k) {
        for(int j = i; ; j += i) {
            if(s.find(j) != s.end()) {
                pos[j].push_back(i);
            } else break;
        }
    }
    map<int, set<pair<int, int>>> mex;
    for(auto q : query) {
        if(q.first == '+') {
            for(auto i : pos[q.second]) {
                addInterval(mex[i], q.second/i, q.second/i + 1);
            }
        } else if(q.first == '-') {
            for(auto i : pos[q.second]) {
                removeInterval(mex[i], q.second/i, q.second/i + 1);
            }
        } else {
            // cout << "Query for - " << q.second << ':';
            // for(auto i : mex[q.second]) {
            //     cout << "{" << i.first << "," << i.second << "} ";
            // }
            // cout << '\n';
            if(mex[q.second].empty()) {
                cout << q.second << '\n';
            } else {
                auto it = mex[q.second].begin();
                if((*it).first != 1) cout << q.second << '\n';
                else cout << (*it).second * q.second << '\n';
            }
        }
    }
    
    return 0;
}