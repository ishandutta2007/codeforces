#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[1002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        cout << n * 3 << "\n";
        for(int i=1;i<=n;i+=2)
        {
            for(int j=1;j<=3;j++){
            cout << "2 " << i << " " << i+1 << "\n";
            cout << "1 " << i << " " << i+1 << "\n";
            }
        }
    }
}