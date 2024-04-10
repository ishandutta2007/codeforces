#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define TT ll t; cin >> t; while(t--)
using namespace std;
ll n;
vector<ll>v;
map<ll,ll>mp,mp1;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    TT
    {
        cin >> n;
        v.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        bool z=true;
        for(int i=1;i<=n;i++)
        {
            if(mp[v[i]]==1)
            {
                z=false;
                break;
            }
        }
        if(!z)
        {
            cout << "-1\n";
            mp.clear();
            mp1.clear();
            continue;
        }
        for(int i=1;i<n;i++)
        {
            if(v[i]!=v[i+1])
            {
                mp1[v[i]]=i;
            }
        }
        mp1[v[n]]=n;
        for(int i=1;i<=n;i++)
        {
            if(v[i]!=v[i-1])
            {
                cout << mp1[v[i]] << " ";
            }
            else
            {
                cout << i-1 << " ";
            }
        }
        cout << "\n";
        mp.clear();
        mp1.clear();
        v.clear();
    }
    return 0;
}