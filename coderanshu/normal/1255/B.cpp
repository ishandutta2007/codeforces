#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
li mod(li x)
{
    return (x>0)?x:-x;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    int t ;
    li n,m,i,ans;
    pair<li,int> a[1001];
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>a[i].first;
            a[i].second=i+1;
            ans+=(2*a[i].first);
        }
        sort(a,a+n);
        if(n==2 || m<n){cout<<"-1\n";continue;}
        cout<<(m-n)*(a[0].first+a[1].first)+ans<<"\n";
        for(i=0;i<n-1;i++)
        {
            cout<<i+1<<" "<<i+2<<"\n";
        }
        cout<<n<<" "<<1<<"\n";
        for(i=1;i<=m-n;i++)
        cout<<a[0].second<<" "<<a[1].second<<"\n";
    }
    return 0;
}