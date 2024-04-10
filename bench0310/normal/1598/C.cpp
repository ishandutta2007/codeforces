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
        map<int,int> m;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m[a[i]]++;
            sum+=a[i];
        }
        ll res=0;
        if(((2*sum)%n)==0)
        {
            ll x=(2*sum)/n;
            for(int i=1;i<=n;i++)
            {
                m[a[i]]--;
                res+=m[x-a[i]];
            }
        }
        cout << res << "\n";
    }
    return 0;
}