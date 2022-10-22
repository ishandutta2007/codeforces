#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        if(n%2 != m%2) i = 1;
        for(;i<n;)
        {
            while(i < n && s[i] != t[j]) i += 2;
            if(i < n) {i++; j++;}
        }

        if(j == m) cout << "YES\n";
        else cout << "NO\n";
    }
}