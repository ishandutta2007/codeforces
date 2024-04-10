#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<ld,int> pli;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100005

vector<int> p[2];
int ac[MAXN],a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    char c;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        a[i]=c-'0';
        ac[i+1]=ac[i]+a[i];
        p[a[i]].push_back(i);
    }

    for(int i=0;i<=n-k;i++)
    {
        int sum=ac[n]-ac[i+k]+ac[i];
        if(!sum || sum==(n-k))
        {
            db("tokitsukaze")
            return 0;
        }
    }

    bool ok=1;
    for(int i=0;i<=n-k;i++)
    {
        ///0
        int l=i,r=i+k-1;
        int l0,r0,r1,l1;
        if(p[1][0]<l || p[1][0]>r)
            l0=p[1][0];
        else
        {
            int pos=upper_bound(p[1].begin(),p[1].end(),r)-p[1].begin();
            if(pos<p[1].size())
                l0=p[1][pos];
            else
                l0=n;
        }

        int last1=p[1].size()-1;
        if(p[1][last1]<l || p[1][last1]>r)
            r0=p[1][last1];
        else
        {
            int pos=lower_bound(p[1].begin(),p[1].end(),l)-p[1].begin();
            if(pos)
                r0=p[1][pos-1];
            else
                r0=0;
        }

        if(r0-l0>=k)
            ok=0;

        ///1
        if(p[0][0]<l || p[0][0]>r)
            l1=p[0][0];
        else
        {
            int pos=upper_bound(p[0].begin(),p[0].end(),r)-p[0].begin();
            if(pos<p[0].size())
                l1=p[0][pos];
            else
                l1=n;
        }

        last1=p[0].size()-1;
        if(p[0][last1]<l || p[0][last1]>r)
            r1=p[0][last1];
        else
        {
            int pos=lower_bound(p[0].begin(),p[0].end(),l)-p[0].begin();
            if(pos)
                r1=p[0][pos-1];
            else
                r1=0;
        }

        if(r1-l1>=k)
            ok=0;
    }

    if(ok)
        db("quailty")
    else
        db("once again")

    return 0;
}