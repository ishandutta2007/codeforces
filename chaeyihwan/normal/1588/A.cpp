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
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(a[i] != b[i] && a[i] != b[i] - 1) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}