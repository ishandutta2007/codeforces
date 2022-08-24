#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(int n, int a){
    int step = n/a;
    int ans = a*(a+1)/2;
    ans *= step;
    ans -= a*(step-1);
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> ans;
    for (int i=1; i*i <= n; i++){
        if (n%i==0){
            ans.insert(solve(n, i));
            ans.insert(solve(n, n/i));
        }
    }
    for (auto it=ans.begin(); it != ans.end(); it++) cout << (*it) << " ";
    return 0;
}