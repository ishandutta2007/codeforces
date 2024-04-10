#include <bits/stdc++.h>

using namespace std;

struct State {
    bool is_beg;
    int at, idx;
    bool operator < (const State &oth) const {
        if (at == oth.at)
            return is_beg < oth.is_beg;
        return at < oth.at;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<string> words(n);
    deque<State> q;
    multiset<pair<int, int>> now;

    int lim = 0;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        int k; cin >> k;
        while (k--) {
            int x; cin >> x; --x;
            q.push_back(State {1, x, i});
            int stop = x + words[i].size();
            q.push_back(State {0, stop, i});
            lim = max(lim, stop);
        }
    }

    sort(q.begin(), q.end());
    

    string ret = "";
    for (int i = 0; i < lim; ++i) {
        //cerr << i << endl;
        assert(q.size());
        while (q.front().at == i) {
            //cerr << "!\n";
            if (!q.front().is_beg) {
                auto it = now.find({q.front().idx, q.front().at - words[q.front().idx].size()});
                assert(it != now.end());
                now.erase(it);
            }
            else now.insert({q.front().idx, q.front().at});

            q.pop_front();
        }

        //cerr << i << " " << now.size() << endl;

        if (now.empty()) ret += 'a';
        else {
            pair<int, int> first = *now.begin();
            assert(i - first.second >= 0);
            assert(i - first.second < words[first.first].size());
            //cerr << first.first << " " << first.second << endl << "!!!\n";
            ret += words[first.first][i - first.second];
        }
    }

    cout << ret << endl;

    return 0;
}