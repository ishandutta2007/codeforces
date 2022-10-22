#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[102], b[102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(a[i] < 0) flag = false;
        }

        if(!flag)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        cout << "101\n";
        for(int i=0;i<=100;i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}