#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[200002];
vector<int> v[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        int x = -1, y = -1;
        for(int i=1;i<=n;i++)
        {
            if(a[i] != a[n-i+1])
            {
                x = a[i];
                y = a[n-i+1];
                break;
            }
        }
        if(x == -1)
        {
            cout << "YES\n";
            continue;
        }

        bool flag = true;
        for(int i=1,j=n;i<j;)
        {
            while(a[i] == x) i++;
            while(a[j] == x) j--;
            if(a[i] != a[j])
            {
                flag = false;
                break;
            }
            i++; j--;
        }

        if(flag)
        {
            cout << "YES\n";
            continue;
        }

        flag = true;
        for(int i=1,j=n;i<j;)
        {
            while(a[i] == y) i++;
            while(a[j] == y) j--;
            if(a[i] != a[j])
            {
                flag = false;
                break;
            }
            i++; j--;
        }

        if(flag)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}