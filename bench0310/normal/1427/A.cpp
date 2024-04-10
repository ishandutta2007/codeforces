#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n,0);
        int s=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            s+=a[i];
        }
        if(s!=0)
        {
            if(s<0) sort(a.begin(),a.end());
            else sort(a.begin(),a.end(),greater<>());
            cout << "YES\n";
            for(int i=0;i<n;i++) cout << a[i] << " \n"[i==n-1];
        }
        else cout << "NO\n";
    }
    return 0;
}