#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    vector<int> v(n,0);
    int idx=0;
    if(n&1)
    {
        for(int i=0;i<n;i+=2) v[i]=a[idx++];
        for(int i=1;i<n;i+=2) v[i]=a[idx++];
    }
    else
    {
        for(int i=0;i<n;i+=2) v[i]=a[idx++];
        v[n-1]=a[idx++];
        for(int i=1;i<n-1;i+=2) v[i]=a[idx++];
    }
    int res=0;
    for(int i=1;i+1<n;i+=2) res+=(v[i-1]>v[i]&&v[i]<v[i+1]);
    cout << res << "\n";
    for(int i=0;i<n;i++) cout << v[i] << " \n"[i==n-1];
    return 0;
}