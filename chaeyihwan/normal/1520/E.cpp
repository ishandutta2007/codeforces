#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '*') c++;
        }
        int d = 0, st = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '*')
            {
                d++;
                if(d == (c + 1)/2) st = i;
            }
        }
        d = 0;
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '*')
            {
                d++;
                int correct = st - ((c+1)/2 - d);
                ans += abs(correct - i);
            }
        }

        cout << ans << "\n";
    }
}