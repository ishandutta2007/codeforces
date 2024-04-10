#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define endl "\n"
#define fori(n)         for (ll i=0; i<n; i++) 
#define forj(n)         for (ll j=0; j<n; j++) 
#define fork(n)         for (ll k=0; k<n; k++) 
#define Sort(a)         sort(a.begin(),a.end())
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    cin>>t;
 
    for(ll i=0;i<t;i++)
    {
        ll n,x;
        cin>>n>>x;
        ll sum=0;
        ll a[n];
        forj(n)
        {
            cin>>a[j];
            sum=sum+a[j];
        }
        if(sum==x)
        cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            ll sol=0;
            forj(n)
            {
                sol=sol+a[j];
                if(sol==x && j!=n-1)
                {
                    sol=sol-a[j];
 
                    sol=sol+a[j+1];
                    swap(a[j],a[j+1]);
                }
                else if(sol==x && j==n-1) {
                    swap(a[n-1],a[0]);
 
                }
            }
            forj(n)
            cout<<a[j]<<" ";
            cout<<endl;
        }
    }
 
     
}