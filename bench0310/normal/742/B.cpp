#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> v((1<<17),0);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        v[a[i]]++;
    }
    ll res=0;
    for(int i=0;i<n;i++)
    {
        v[a[i]]--;
        res+=v[a[i]^x];
    }
    cout << res << "\n";
    return 0;
}