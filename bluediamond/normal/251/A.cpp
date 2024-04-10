#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,d; cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    ll ans=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        int st=i,dr=n-1;
        int lst=i;
        while(st<=dr)
        {
            int mid=(st+dr)/2;
            if(v[mid]<=v[i]+d) {lst=mid; st=mid+1;} else dr=mid-1;
        }
        ll x=lst-i;
        ans+=(x-1)*x/2;
    }
    cout<<ans<<"\n";
}
/**

**/