#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-6);
const ll INF=ll(1e18);
const int sINF=int(1e9);
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef multiset<int>::iterator stit;
typedef long long ll;
using namespace std;

vector<ll> dp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(3);
    ll ti=2;
    while(dp.back()<=INF&&ti++)
        dp.push_back(dp[ti-1]+dp[ti-2]);
    dp.push_back(dp[ti]+dp[ti-1]);
    //cout<<ti<<endl;
    ll n;
    cin>>n;
    for(int i=0;i<dp.size();i++)
    {
        if(dp[i]>n)
        {
            //cout<<dp[i-1]<<endl;
            cout<<i-1<<endl;
            return 0;
        }
    }

}