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
        vector<int> v1(n), v2(n);
        for(int i=0;i<n;i++)
        {
            v1[i] = v2[i] = s[i] - 'a';
        }
        sort(v2.begin(), v2.end());

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(v1[i] != v2[i]) ans++;
        }
        cout << ans << "\n";
    }
}