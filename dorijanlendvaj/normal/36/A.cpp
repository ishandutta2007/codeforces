/**
*!! Abhimanyu Bano !!
*!!       !!
* @Author  : Abhinandan Mishra
*
**/
#include <bits/stdc++.h> 
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb        push_back
#define ppb       pop_back
#define pf        push_front
#define ppf       pop_front
#define all(x)    (x).begin(),(x).end()
#define uniq(v)   (v).erase(unique(all(v)),(v).end())
#define f        first
#define s        second
#define pll       pair<ll,ll>
#define vll        vector<ll>
#define vpll        vector<pair<ll,ll>>
#define mll          map<ll,ll>
#define umll          unordered_map<ll,ll>
#define usll          unordered_set<ll>
#define debug(x) cerr<<'\n'<<(#x)<<" is "<<(x)<<endl;
#define sll          set<ll>
#define FILL(arr)         for(ll i=0;i<n;i++)cin>>arr[i];
#define fill(arr)         for(ll i=0;i<n;i++){ ll k; cin>>k;arr.pb(k); }
#define Print(arr)         for(ll i=0;i<n;i++)cout<<arr[i]<<' ';
#define charcountmap(s)         for(ll i=0;i<s.length();i++)mp[s[i]]++;
#define rep(i,n)   for(ll i=0;i<n;i++)
#define repe(i,a,b)   for(ll i=a;i<=b;i++)
#define mem1(a)      memset(a,-1,sizeof(a))
#define mem0(a)      memset(a,0,sizeof(a))
#define INF 100000000000000000
#define mod 1000000007
#define esp 10e-7
const int mx=1e5+7;

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


ll power(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=ans*a;b--;
    }
        b/=2;
        a=a*a;
    }
    return ans;
}
bool check(string s,int i,int n,int count){
    
    while(i<n){
        int j=i+1;
        int k=0;
        while(j<n && s[j]=='0'){
            k++;
            j++;
        }
        if(k!=count && j<n){
            
            return false;
        }
        i=j;
    }
    return true;
    }
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    while(i<n &&s[i]=='0'){
        i++;
    }
    int count=0;
    i++;
    while(i<n && s[i]=='0'){
        i++;
        count++;
    }
    if(check(s,i,n,count)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    IOS
    ll t=1;
    ll i=0;
    while(i++<t){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}