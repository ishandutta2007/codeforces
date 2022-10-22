#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool u[26];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        for(int i=0;i<26;i++) u[i] = false;
        bool flag = true;
        int now = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i-1] != s[i] && u[s[i]-'A']) flag = false;
            u[s[i] - 'A'] = true;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}