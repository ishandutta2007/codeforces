#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

string s;

bool chk(int pos)
{
    int n = s.size();
    if(pos + 2 < n) if(s[pos] == 'a' && s[pos+1] == 'b' && s[pos+2] == 'c') return true;
    if(pos + 1 < n && pos > 0) if(s[pos-1] == 'a' && s[pos] == 'b' && s[pos+1] == 'c') return true;
    if(pos > 1) if(s[pos-2] == 'a' && s[pos-1] == 'b' && s[pos] == 'c') return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; t = 1;
    while(t--){
        int n, q; cin >> n >> q;
        cin >> s;
        int k = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] - 'a' == k) k++;
            else k = 0;
            if(s[i] == 'a') k = 1;
            if(k == 3)
            {
                ans++;
                k = 0;
            }
        }

        for(int i=1;i<=q;i++)
        {
            int pos; char c; cin >> pos >> c;
            pos--;
            if(chk(pos)) ans--;
            s[pos] = c;
            if(chk(pos)) ans++;
            cout << ans << "\n";
        }
    }
}