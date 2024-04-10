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
        if(k > (n+1)/2) cout << "-1\n";
        else
        {
            for(int i=1;i<=k;i++)
            {
                for(int j=1;j<=2*i-2;j++) cout << ".";
                cout << "R";
                for(int j=1;j<=n-2*i+1;j++) cout << ".";
                cout << "\n";
                if(i == k) break;
                for(int j=1;j<=n;j++) cout << ".";
                cout << "\n";
            }
            for(int i=1;i<=n-2*k+1;i++)
            {
                for(int j=1;j<=n;j++) cout << ".";
                cout << "\n";
            }
        }
    }
}