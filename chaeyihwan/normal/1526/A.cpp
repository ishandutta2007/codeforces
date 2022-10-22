#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[52];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=2*n;i++) cin >> a[i];

        sort(a + 1, a + 2*n + 1);

        for(int i=1;i<=n;i++)
        {
            cout << a[i] << " " << a[i+n] << " ";
        }
        cout << "\n";
    }
}