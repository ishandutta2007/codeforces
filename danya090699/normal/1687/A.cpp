#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int pref[n+1], k2=min(k, n), ma=0;
        pref[0]=0;
        for(int a=1; a<=n; a++)
        {
            scanf("%lld", &pref[a]);
            pref[a]+=pref[a-1];
            if(a>=k2) ma=max(ma, pref[a]-pref[a-k2]);
        }
        cout<<((k-1)+(k-k2))*k2/2+ma<<"\n";
    }
}