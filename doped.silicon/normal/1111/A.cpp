#include<bits/stdc++.h>
using namespace std;
 #include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace __gnu_pbds;  
using namespace std;

// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
#define ll long long
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
 
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define debug(x) cout<<#x<<": "<<x<<endl
 
#define ld double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000000000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long double pi= 3.14159265358979323846;
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length())
    {
        cout<<"No";
    }
    else
    {
        rep(i,s1.length())
        {
            if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
            {
                if(!(s2[i]=='a'||s2[i]=='e'||s2[i]=='i'||s2[i]=='o'||s2[i]=='u'))
                {
                    cout<<"No";
                    return 0;
                }
            }
            if((s2[i]=='a'||s2[i]=='e'||s2[i]=='i'||s2[i]=='o'||s2[i]=='u'))
            {
                if(!(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u'))
                {
                    cout<<"No";
                    return 0;
                }
            }
        }
        cout<<"Yes";
    }
    return 0;
}