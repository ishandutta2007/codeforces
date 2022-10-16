//  228

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define endl "\n"
#define trap_time() std::chrono::high_resolution_clock::now()
#define trap_time_diff(a,b) 1e-9 * std::chrono::duration_cast<std::chrono::nanoseconds>(a - b).count()
#define fr(i,s,k,b) for(int i=s;i<=k;i+=b)
#define fast() ios::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
using namespace std;
int main()
{
    fast();
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<int,int> p[n];
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            p[i]=mp(a,b);
        }
        sort(p,p+n);
        int ans=0;
        int mx=p[0].second;
        for(int i=1;i<n;i++)
        {
            if(p[i].second>=mx)
                mx=p[i].second;
            else
                ans++;
        }
        cout<<ans<<endl;
    }
}