//  228

#include<bits/stdc++.h>
using namespace std;
long mod=1e9+7;
#define pb push_back
#define pf push_front
#define ins insert
#define ll long long
#define fastio {    ios_base::sync_with_stdio(false);cin.tie(NULL);}
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll exp(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n&1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
ll maxx=1;
bool func(ll a[],ll b[],ll n,ll m,ll r)
{
    ll i=0,j=0;
    while(i<n&&j<m)
    {
        int k=abs(a[i]-b[j]);
        if(k<=r)
        {
            i++;
        }
        else
            j++;
    }
    return (i>=n);
}
int main()
{
    ll minn=INT_MAX;
    ll c,m,n,k,l;
    ll a,b;
    cin>>a>>b;
    k=__gcd(a,b);
    vector<int>v;
    for(int i=1;i<=sqrt(k);i++)
    {
        if(k%i==0)
        {
            v.push_back(i);
            v.push_back(k/i);
        }
    }
    sort(v.begin(),v.end()); 
    vector<int>v1;
    for(auto x:v)
    {
        if(v1.size()==0)
            v1.push_back(x);
        else
        {
            if(v1[v1.size()-1]!=x)
                v1.push_back(x);
        }
    }
   
   
   
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        int k1=lower_bound(v1.begin(),v1.end(),a)-v1.begin();
        int k2=upper_bound(v1.begin(),v1.end(),b)-v1.begin();
        if(k1==v1.size())
            cout<<"-1";
        else
        {
            
                k2--;
            int ans=v1[k2];
            if(ans<a)
                cout<<"-1";
            else
                cout<<ans;
        }
        cout<<endl;
    }
   
 

}