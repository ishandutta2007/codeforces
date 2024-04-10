#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n == 4 && k == 3)
        {
            cout << "-1\n";
            continue;
        }
        if(k == 0)
        {
            for(int i=0;i<n/2;i++) cout << i << " " << (n-1-i) << "\n";
            continue;
        }
        if(k < n-1)
        {
            cout << k << " " << n-1 << "\n";
            cout << ((n-1)^k) << " " << 0 << "\n";
            for(int i=1;i<n/2;i++) if(i != k && i != ((n-1)^k)) cout << i << " " << (n-1-i) << "\n";
            continue;
        }
        cout << k << " " << k-1 << "\n";
        cout << "1 3\n";
        cout << 0 << " " << k-3 << "\n";
        cout << 2 << " " << k-2 << "\n";
        for(int i=4;i<n/2;i++) cout << i << " " << (n-1-i) << "\n";
    }
}