#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l;
    cin>>n>>l;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x; v.pb(x);
    }
    sort(v.begin(),v.end());
    int ans=0;
    ans=max(ans,2*v[0]);
    ans=max(ans,2*(l-v.back()));
    for(int i=0;i+1<n;i++)
    {
        ans=max(ans,v[i+1]-v[i]);
    }
    cout<<ans/2;
    if(ans%2) cout<<".5";
}
/**



**/