#include<bits/stdc++.h>
using namespace std;
int n, k;
string s;
#define rep(x,l,r) for (int x = l;x<r;x++)
inline void input(){    cin >> n >> k >> s;}
void output(vector<int> &del){
    for (int i = 0; i < n; ++i) {
        int now = s[i] - 'a';
        if (del[now]) {
            del[now]--;
            continue;
        }
        cout<<s[i];
    }
}
int main() {
    input();
    vector<int> del(26, 0);
    vector<int> cnt(26, 0);
    for(char c:s){
        cnt[c-'a']++;
    }
    for(int i = 0; i < 26 && k; ++i) {
        if (k >= cnt[i]) {
            del[i] = cnt[i];
            k -= cnt[i];
        } else {
            del[i] = k;
            break;
        }
    }
    output(del);
    return 0;
}