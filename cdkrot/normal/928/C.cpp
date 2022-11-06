#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000;

map<pair<string, int>, int> mmap;
map<string, pair<int, int> > ans;

vector<pair<string, int> > v[maxn];
pair<string, int> name[maxn];
vector<int> g[maxn];

int d[maxn];

vector<pair<string, int> > res;

int main() {

    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        int k;
        cin >> s >> k;
        mmap[{s, k}] = i;
        name[i] = {s, k};
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            string t;
            int x;
            cin >> t >> x;
            v[i].push_back({t, x});
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)v[i].size(); ++j) {
            g[i].push_back(mmap[v[i][j]]);
        }
    }
	vector<int> q1, q2;
    for (int i = 0; i < n; ++i) d[i] = -1;
    d[0] = 0;
	q1.push_back(0);
	while (q1.size() > 0) {
		for (int i = 0; i < (int)q1.size(); ++i) {
			if (ans.find(name[q1[i]].first) == ans.end()) {
		        ans[name[q1[i]].first] = {-d[q1[i]], name[q1[i]].second};
		    } else {
		        ans[name[q1[i]].first] = max(ans[name[q1[i]].first], {-d[q1[i]], name[q1[i]].second});
		    }
		}
		vector<int> q;
		for (int i = 0; i < (int)q1.size(); ++i) {
			if (ans[name[q1[i]].first] > make_pair(-d[q1[i]], name[q1[i]].second)) {
				d[q1[i]] = -1;
			} else {
				q.push_back(q1[i]);
			}
		}
		for (int i = 0; i < (int)q.size(); ++i) {
			int v = q[i];
			for (int j = 0; j < (int)g[v].size(); ++j) {
				int x = g[v][j];
		        if (d[x] == -1) {
		            d[x] = d[v] + 1;
		            q2.push_back(x);
		        }
			}
		}
		q1.resize(q2.size());
		for (int i = 0; i < (int)q1.size(); ++i) {
			q1[i] = q2[i];
		}
		q2.clear();
	}

    for (int i = 0; i < n; ++i) {
		if (d[i] > 0) {
	        res.push_back(name[i]);
		}
    }
    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (int i = 0; i < (int)res.size(); ++i) {
        cout << res[i].first << ' ' << res[i].second << "\n";
    }

    return 0;
}