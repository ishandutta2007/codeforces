#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[1002][502], b[1002][502];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size();
        bool ans = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool flag = true;
                if(s[i] != t[0]) break;
                for(int k=1;k<=j;k++)
                {
                    if(i+k>=n) flag = false;
                    if(s[i+k] != t[k]) flag = false;
                    if(!flag) break;
                }
                for(int k=1;k<m-j;k++)
                {
                    if(i+j-k < 0) {flag = false; break; }
                    if(s[i+j-k] != t[j+k]) flag = false;
                    if(!flag) break;
                }

                if(flag) { ans = true; break;}
            }
            if(ans) break;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}