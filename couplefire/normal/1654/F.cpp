#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; string s;
    cin >> n >> s;
    vector<int> ord(1<<n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){return s[a]<s[b];});
    vector<int> v(1<<n, 0);
    for(int i = 1; i<(1<<n); ++i)
        v[ord[i]] = v[ord[i-1]]+(s[ord[i-1]]<s[ord[i]]);
    for(int t = 0; t<n; ++t){
        auto cmp = [&](int a, int b){
            return v[a]==v[b]?v[a^(1<<t)]<v[b^(1<<t)]:v[a]<v[b];
        };
        sort(ord.begin(), ord.end(), cmp);
        vector<int> tmp(1<<n, 0);
        for(int i = 1; i<(1<<n); ++i)
            tmp[ord[i]] = tmp[ord[i-1]]+(cmp(ord[i-1], ord[i]));
        swap(v, tmp);
    }
    for(int i = 0; i<(1<<n); ++i)
        cout << s[i^ord[0]];
}