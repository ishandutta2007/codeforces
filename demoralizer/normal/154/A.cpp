#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>

int n;
string s;
int dp[100005][28];
set<pii> f;
int calc(int pos,char c){
	if(pos==n)return 0;
	int& ans=dp[pos][c-'a'];
	if(ans!=-1)return ans;
	ans=1+calc(pos+1,c);
	if(f.find({c,s[pos]})==f.end())ans=min(ans,calc(pos+1,s[pos]));
	return ans;
}
void solve(){
	memset(dp,-1,sizeof(dp));
    cin>>s;
    n=s.size();
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
    	string t;
    	cin>>t;
    	f.insert({t[0],t[1]});
    	f.insert({t[1],t[0]});
    }
    if(n==1)cout<<0;
    else
    cout<<calc(0,'z'+2);
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}