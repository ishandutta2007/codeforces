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
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            int a; cin >> a;
            sum += a;
        }

        if(sum < n) cout << "1\n";
        else if(sum == n) cout << "0\n";
        else cout << sum - n << "\n";
    }
}