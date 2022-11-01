#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll res=0;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin >> a;
        q.push(a);
    }
    if((n%2)==0) q.push(0);
    while(q.size()>1)
    {
        ll a=q.top();
        q.pop();
        ll b=q.top();
        q.pop();
        ll c=q.top();
        q.pop();
        res+=(a+b+c);
        q.push(a+b+c);
    }
    cout << res << "\n";
    return 0;
}