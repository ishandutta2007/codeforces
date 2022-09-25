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
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a) 
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
using namespace std;
using namespace __gnu_pbds;
 
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
 
inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}
 
const int maxn=1000005;
//i_am_noob
int t,l,r,hash1[2],hash2[2],ans[2],noob[maxn][2];
string str,str1,str2;
bool ok;

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	noob[0][0]=noob[0][1]=1;
	rep2(i,1,maxn) rep1(j,2) noob[i][j]=noob[i-1][j]*(j?10015457:20020607)%MOD;
	cin >> t;
	while(t--){
		cin >> str;
		l=0,r=sz(str)-1;
		ok=false;
		while(1){
			if(r<=l){
				print1(str);
				ok=true;
				break;
			}
			if(str[l]!=str[r]) break;
			l++,r--;
		}
		if(ok) continue;
		str1=str.substr(0,l);
		str2=str.substr(r+1,sz(str)-r-1);
		str=str.substr(l,r-l+1);
		hash1[0]=hash1[1]=hash2[0]=hash2[1]=0;
		rep(sz(str)){
			rep1(j,2) hash1[j]=(hash1[j]*(j?10015457:20020607)+(str[i]-'a'+1))%MOD;
			rep1(j,2) hash2[j]=add(hash2[j],(str[i]-'a'+1)*noob[i][j]%MOD);
			if(hash1[0]==hash2[0]&&hash1[1]==hash2[1]) ans[0]=i;
		}
		hash1[0]=hash1[1]=hash2[0]=hash2[1]=0;
		rep3(i,sz(str)-1,0){
			rep1(j,2) hash1[j]=(hash1[j]*(j?10015457:20020607)+(str[i]-'a'+1))%MOD;
			rep1(j,2) hash2[j]=add(hash2[j],(str[i]-'a'+1)*noob[sz(str)-1-i][j]%MOD);
			if(hash1[0]==hash2[0]&&hash1[1]==hash2[1]) ans[1]=i;
		}
		if(ans[0]+1>sz(str)-ans[1]) cout << str1 << str.substr(0,ans[0]+1) << str2 << '\n';
		else cout << str1 << str.substr(ans[1],sz(str)-ans[1]) << str2 << '\n';
	}
	return 0;
}