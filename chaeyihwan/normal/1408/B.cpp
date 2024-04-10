#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];

        int c = 1;
        for(int i=2;i<=n;i++)
        {
            if(a[i] != a[i-1]) c++;
        }

        if(k == 1 && c > 1)
        {
            cout << "-1\n";
            continue;
        }
        if(k == 1 || c == 1)
        {
            cout << "1\n";
            continue;
        }

        int m = (c-1+k-2)/(k-1);

        cout << m << "\n";
    }
}