#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=4000045;
vector<array<int,2>> trie(N,{0,0});
int tidx=1;

void add(ll a)
{
    int idx=0;
    for(ll i=39;i>=0;i--)
    {
        int b=((a>>i)&1);
        if(trie[idx][b]==0) trie[idx][b]=tidx++;
        idx=trie[idx][b];
    }
}

ll query(ll a)
{
    int idx=0;
    ll res=0;
    for(ll i=39;i>=0;i--)
    {
        int b=((a>>i)&1);
        if(trie[idx][1-b]!=0)
        {
            idx=trie[idx][1-b];
            res+=(1ll<<i);
        }
        else idx=trie[idx][b];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    ll a=0;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        a^=v[i];
    }
    add(0);
    ll res=a;
    ll b=0;
    for(ll i=n-1;i>=0;i--)
    {
        b^=v[i];
        add(b);
        a^=v[i];
        res=max(res,query(a));
    }
    cout << res << "\n";
    return 0;
}