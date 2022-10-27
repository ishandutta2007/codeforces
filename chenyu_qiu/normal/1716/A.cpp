//
#include <bits/stdc++.h>
using namespace std;
 
#define pi 3.141592653
#define ll long long
#define mod 1000000007
#define MAX 1e18+1
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define double dd
#define pb push_back
#define pii pair<int,int> 
 
void solve()
{
    //std::cout << std::fixed << std::setprecision(6);
    
    int n;
    cin>>n;
    if(n==1) cout<<2;
    else if(n%3==0) cout<<n/3;
    else cout<<n/3+1;
}
 
int main()
{   ios::sync_with_stdio(0);
    cin.tie(0);
    // cout<<('v'<='y' && 'v'>='p');
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    //form();
 
    int t=1;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
        cout<<"\n";
    }
    
	return 0;
}