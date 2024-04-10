#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, K;
    cin >> N;
    cin >> K;
    string s;
    cin >> s;
    vector<int> nxt(N);
    vector<int> fst(26);
    vector<int> lst(26, N);
    for(int i=s.size()-1;i>=0;--i) {
        int t = s[i]-'a';
        nxt[i] = lst[t];
        lst[t] = i;
    }
    for(int i=0;i<26;++i) {
        fst[i] = lst[i];
    }
    vector<bool> have(N, 1);
    int h = 0;
    for(int i=0;i<K;++i) {
        while(fst[h] == N) ++h;
        have[fst[h]] = 0;
        fst[h] = nxt[fst[h]];
    }
    for(int i=0;i<N;++i) {
        if(have[i]) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}