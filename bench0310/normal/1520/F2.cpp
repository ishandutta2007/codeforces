#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
typedef long long ll;
 
template <class T>
using ordered_set=__gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

//*find_by_order(idx)
//order_of_key(val)
//both 0-indexed

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    int k;
    cin >> k;
    ordered_set<int> s;
    vector<int> q(n+1,-1);
    auto qry=[&](int r)->int
    {
        auto it=s.upper_bound(r);
        int c=0;
        if(it!=s.begin())
        {
            it--;
            c=s.order_of_key(*it)+1;
        }
        if(q[r]==-1)
        {
            cout << "? " << 1 << " " << r << "\n";
            cout.flush();
            cin >> q[r];
            q[r]-=c;
        }
        return (q[r]+c);
    };
    auto ans=[&](int p)
    {
        cout << "! " << p << "\n";
        cout.flush();
        t--;
        s.insert(p);
        if(t==0) exit(0);
        cin >> k;
    };
    while(1)
    {
        int l=0,r=n;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(m-qry(m)>=k) r=m;
            else l=m;
        }
        ans(r);
    }
    return 0;
}