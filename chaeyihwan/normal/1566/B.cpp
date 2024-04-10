#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();

        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(s[i] == '1' && s[i-1] == '0') ans++;
        }
        if(s[n-1] == '0') ans++;
        cout << min(2, ans) << "\n";
    }
}