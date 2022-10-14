#include <bits/stdc++.h>
using namespace std;

struct query {
    int val, id;
    const bool operator<(const query other) const {
        return val < other.val;
    }
};
vector<query> qu;

char ans[500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    for(int i=0; i<q; i++) {
        int v; cin >> v;
        qu.push_back({v, i});
    }
    sort(qu.begin(), qu.end());
    int curLetters = 0, curNext = 1, nextUnanswered = 0;
    string s = "";
    while(nextUnanswered != q) {
        s += to_string(curNext); curNext++;
        while(nextUnanswered != q && qu[nextUnanswered].val <= curLetters + s.length()) {
            ans[qu[nextUnanswered].id] = s[qu[nextUnanswered].val-curLetters-1];
            nextUnanswered++;
        }
        curLetters += s.length();
    }
    for(int i=0; i<q; i++) cout << ans[i] << endl;
}