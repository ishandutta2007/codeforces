#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define chrng(n,a,b)      (((n)>=(a))&&((n)<=(b)))
#define clamp(n,a,b)      (((n)<(a))?(a):((((n)>(b))?(b):(n)))

int arr[100005];
string s,t,a;
void solve(){
	int n,k=0;
	cin>>n>>s>>t;
	if(s[0]==s[1])k++;
	if(t[0]==t[1])k++;
	cout<<"YES\n";
	if(k==2)rep(i,0,n)cout<<"abc";
	else if(k==1){
		if(s[0]==s[1])swap(s,t);
		a+=s[1];
		a+=s[0];
		a+=('a'!=s[0]&&'a'!=s[1])?'a':(('b'!=s[0]&&'b'!=s[1])?'b':'c');
		rep(i,0,n)cout<<a;
	}
	else{
		if(s[0]==t[1]&&t[0]==s[1]){
			rep(i,0,n)cout<<s[0];
			char c=('a'!=s[0]&&'a'!=s[1])?'a':(('b'!=s[0]&&'b'!=s[1])?'b':'c');
			rep(i,0,n)cout<<c;
			rep(i,0,n)cout<<s[1];
		}
		else if(s[0]==t[0]){
			a=(s[0]=='a')?"bc":((s[0]=='b')?"ac":"ab");
			rep(i,0,n)cout<<a;
			rep(i,0,n)cout<<s[0];
		}
		else if(s[1]==t[1]){
			a=(s[1]=='a')?"bc":((s[1]=='b')?"ac":"ab");
			rep(i,0,n)cout<<s[1];
			rep(i,0,n)cout<<a;
		}
		else{
			a+=s[1];
			a+=s[0];
			a+=('a'!=s[0]&&'a'!=s[1])?'a':(('b'!=s[0]&&'b'!=s[1])?'b':'c');
			rep(i,0,n)cout<<a;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}