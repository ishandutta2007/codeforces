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
        ll sum=0;
        multiset<ll> s;
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            s.insert(a);
            sum+=a;
        }
        queue<ll> q;
        q.push(sum);
        bool ok=1;
        int cnt=0;
        while(!q.empty())
        {
            ll a=q.front();
            q.pop();
            if(s.contains(a)) s.erase(s.find(a));
            else
            {
                if(a==1||cnt==n-1)
                {
                    ok=0;
                    break;
                }
                cnt++;
                q.push(a/2);
                q.push(a-a/2);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}