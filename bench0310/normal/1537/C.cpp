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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        int x=1;
        for(int i=2;i<n;i++) if(a[i+1]-a[i]<a[x+1]-a[x]) x=i;
        cout << a[x] << " ";
        for(int i=x+2;i<=n;i++) cout << a[i] << " ";
        for(int i=1;i<x;i++) cout << a[i] << " ";
        cout << a[x+1] << "\n";
    }
    return 0;
}