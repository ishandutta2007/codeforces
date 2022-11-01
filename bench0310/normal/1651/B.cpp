#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const ll lim=1000000000;
    vector<ll> a={1};
    while(3*a.back()<=lim) a.push_back(3*a.back());
    int sz=a.size();
    while(t--)
    {
        int n;
        cin >> n;
        if(n<=sz)
        {
            cout << "YES\n";
            for(int i=0;i<n;i++) cout << a[i] << " \n"[i==n-1];
        }
        else cout << "NO\n";
    }
    return 0;
}