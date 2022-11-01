#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int spells=0;
    set<int> l;
    set<int> big;
    set<int> small;
    ll sum=0;
    ll sumbig=0;
    auto balance=[&]()
    {
        while(big.size()>l.size())
        {
            int x=(*big.begin());
            big.erase(big.begin());
            sumbig-=x;
            small.insert(x);
        }
        while(big.size()<l.size())
        {
            int x=(*small.rbegin());
            small.erase(x);
            sumbig+=x;
            big.insert(x);
        }
        while((!small.empty())&&(!big.empty())&&(*small.rbegin())>(*big.begin()))
        {
            int x=(*small.rbegin());
            int y=(*big.begin());
            sumbig+=(x-y);
            small.erase(x);
            big.erase(y);
            small.insert(y);
            big.insert(x);
        }
    };
    while(n--)
    {
        int t,d;
        cin >> t >> d;
        if(d>0)
        {
            spells++;
            sum+=d;
            if(t==1) l.insert(d);
            small.insert(d);
        }
        else
        {
            spells--;
            d=-d;
            sum-=d;
            if(t==1) l.erase(d);
            if(small.find(d)!=small.end()) small.erase(d);
            else
            {
                big.erase(d);
                sumbig-=d;
            }
        }
        balance();
        if((int)l.size()==spells) cout << 2*sum-(*l.begin()) << "\n";
        else if(l.empty()) cout << sum << "\n";
        else
        {
            ll res=sum+sumbig;
            int x=(*l.begin());
            if(big.find(x)!=big.end()) res+=((*small.rbegin())-x);
            cout << res << "\n";
        }
    }
    return 0;
}