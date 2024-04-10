#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int sz = s.size();
    int ans = 0;
    int L = 0, R = 0;
    for (int i=0; i < sz; i++){
        L *= 2, R *= 2;
        L += (s[i] - 'a'), R += (t[i] - 'a');
        if (R-L+1>=k){
            for (int j=i; j < sz; j++) ans += k;
            break;
        }
        ans += R-L+1;
    }
    cout << ans;
}