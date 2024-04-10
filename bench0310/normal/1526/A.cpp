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
        vector<int> a(2*n);
        for(int i=0;i<2*n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        vector<int> b(2*n);
        for(int i=0;i<n;i++) b[2*i]=a[i];
        for(int i=0;i<n;i++) b[2*i+1]=a[i+n];
        for(int i=0;i<2*n;i++) cout << b[i] << " \n"[i==2*n-1];
    }
    return 0;
}