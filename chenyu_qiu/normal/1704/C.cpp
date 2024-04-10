#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
void solve()
{
    ll n, m;
    cin>>n>>m;
 
 
    vector<ll> a(m);
    for(ll i= 0; i<m; i++)
        cin>>a[i];
 
    priority_queue<ll> q;
    sort(a.begin(), a.end());
 
    for(ll i = 1; i < m; i++)
    {
        q.push(a[i] - a[i-1] - 1);
    }
 
    ll temp = a[0] - 1;
    temp += n - a[m- 1];
    q.push(temp);
 
 
    int curr = 0;
    ll count = 0;
    while(!q.empty())
    {
        ll t = q.top();
        q.pop();
        t -= 2*curr;
        if(t > 1)
         {
            count += t - 1;
            curr += 2;
         }
 
        else if(t == 1){
            count += 1;
            curr += 1;
        }
    }
    cout<< n - count<<"\n";
}
 
int main()
{
   int t;
   cin>>t;
 
   while(t--)
   {
        solve();
   }
 
    return 0;
}