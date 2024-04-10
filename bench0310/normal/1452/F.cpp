#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<ll> st(n,0);
    for(int i=0;i<n;i++) cin >> st[i];
    vector<ll> two(n,1);
    for(int i=1;i<n;i++) two[i]=(two[i-1]*2);
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int pos,val;
            cin >> pos >> val;
            st[pos]=val;
        }
        else
        {
            int x;
            ll k;
            cin >> x >> k;
            ll res=(1ll<<60);
            ll ops=0;
            ll pos=0;
            for(int i=0;i<n;i++) pos+=(st[i]*two[i]);
            if(pos<k)
            {
                cout << "-1\n";
                continue;
            }
            ll small=0;
            for(int i=0;i<=x;i++)
            {
                small+=(st[i]*(two[i]-1));
                k-=st[i];
            }
            if(k<=0)
            {
                cout << "0\n";
                continue;
            }
            int idx=-1;
            for(int i=x+1;i<n;i++)
            {
                ll c=min(st[i],k/two[i-x]);
                k-=(c*two[i-x]);
                ops+=(c*(two[i-x]-1));
                small+=(c*two[i-x]*(two[x]-1));
                if(st[i]-c>0&&two[i-x]>k)
                {
                    idx=i;
                    break;
                }
            }
            for(int i=idx;i>x;i--)
            {
                if(k<=0) break;
                if(small>=k) res=min(res,ops+k);
                ops++;
                if(i==x+1)
                {
                    small+=(2*(two[x]-1));
                    k-=2;
                    break;
                }
                if(two[i-x-1]<=k)
                {
                    ops+=(two[i-x-1]-1);
                    small+=(two[i-x-1]*(two[x]-1));
                    k-=(two[i-x-1]);
                }
            }
            if(k>0)
            {
                assert(small>=k);
                ops+=k;
            }
            res=min(res,ops);
            cout << res << "\n";
        }
    }
    return 0;
}