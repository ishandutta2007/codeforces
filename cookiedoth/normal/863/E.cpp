#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 300000;
set<int> s;
int n;
vector<pair<int, int> > events;
bool useful[mx];

void use(int i) {
    if (events[i].second > 0)
        s.insert(events[i].second);
    else
        s.erase(-events[i].second);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, i});
        events.push_back({r + 1, -i});
    }
    sort(events.begin(), events.end());
    int ptr = 0;
    while (ptr < events.size()) {
        use(ptr);
        while (ptr < events.size() && events[ptr].first == events[ptr+1].first) {
            ptr++;
            use(ptr);
        }
        ptr++;
        if (s.size() == 1) {
            useful[*s.begin()] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (useful[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}