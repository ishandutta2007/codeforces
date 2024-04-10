#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define debug(a) print2(#a,a)
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
int dgts2(int n){return (n?dgts2(n>>1)+1:0);}
int dgts(int n, int k){return (n?dgts(n/k,k)+1:0);}
inline int v2(int n){return __builtin_ctzll(n);}
 
const int maxn=5005;
//i_am_noob
int t,n,ans,l,r;
string str,str1,str2;
bool ok;

bool noob(string str){
	string tmp;
	tmp=str;
	reverse(all(str));
	if(str==tmp) return true;
	return false;
}
 
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> str;
		n=sz(str);
		ans=0;
		str1.clear(),str2.clear();
		l=0,r=n-1;
		ok=false;
		while(1){
			if(str[l]!=str[r]) break;
			if(l+1>=r){
				ok=true;
				print1(str);
				break;
			}
			l++,r--;
		}
		if(ok) continue;
		rep3(i,r,l){
			if(noob(str.substr(l,i-l+1))){
				str1=str.substr(l,i-l+1);
				break;
			}
		}
		rep2(i,l,r+1){
			if(noob(str.substr(i,r-i+1))){
				str2=str.substr(i,r-i+1);
				break;
			}
		}
		if(sz(str1)>sz(str2)){
			if(l>0) cout << str.substr(0,l) << str1 << str.substr(r+1,l) << '\n';
			else print1(str1);
		}
		else{
			if(l>0) cout << str.substr(0,l) << str2 << str.substr(r+1,l) << '\n';
			else print1(str2);
		}
	}
	return 0;
}