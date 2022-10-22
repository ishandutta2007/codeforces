#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[102];
int cnt[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int k = n-1;
        if(n == 1 || s[0] == s[1])
        {
            cout << s[0] << s[0];
            cout << "\n";
            continue;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i] < s[i+1])
            {
                k = i;
                break;
            }
        }
        for(int i=0;i<=k;i++) cout << s[i];
        for(int i=k;i>=0;i--) cout << s[i];
        cout << "\n";
    }
}