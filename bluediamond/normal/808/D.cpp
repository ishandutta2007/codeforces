#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000+5;

int n;
int v[N];
ll sum=0LL;

bool iint(ll x)
{
    if(0<=x && x<=2000000000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    multiset<int>s1,s2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        sum+=v[i];
        s2.insert(2*v[i]);
    }
    ll st=0LL;
    for(int i=0;i<=n;i++)
    {
        st+=v[i];
        ll dr=sum-st;
        if(i)
        {
            auto it=s2.find(2*v[i]);
            s2.erase(it);
            s1.insert(2*v[i]);
        }
       /** cout<<"\t:";
        for(auto x:s1) cout<<x<<" ";
        cout<<"\n\t:";
        for(auto x:s2) cout<<x<<" ";
        cout<<"\n"; **/
        if(st<dr)
        {
            ll value=dr-st;
          ///  cout<<st<<" "<<dr<<" , "<<value<<"\n";
            if(iint(value) && s2.find(value)!=s2.end())
            {
                cout<<"YES\n";
                return 0;
            }
        }
        else
        {
            ll value=st-dr;
          ///  cout<<st<<" "<<dr<<"\n";
            if(iint(value) && s1.find(value)!=s1.end())
            {
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}