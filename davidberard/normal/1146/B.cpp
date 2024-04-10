#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

string t;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    int last = -1;
    int cnt = 0;
    for(int i=0;i<t.size();++i) {
        if(t[i] == 'a') last = i;
    }
    for(int i=0;i<last;++i) {
        cnt += t[i] != 'a';
    }
    for(int i=last+1;i<=t.size();++i) {
        if(t.size()-i == cnt) {
            int b = 0;
            for(int j=i; j<t.size(); ++j) {
                while(t[b] == 'a') {
                    ++ b;
                }
                if(t[b] != t[j]) {
                    cout << ":(" << endl;
                    return 0;
                }
                ++b;
            }
            cout << t.substr(0, i) << endl;
            return 0;
        }
        if(i == t.size()) break;
        cnt += t[i] != 'a';
    }
    cout << ":(" << endl;
    return 0;
}