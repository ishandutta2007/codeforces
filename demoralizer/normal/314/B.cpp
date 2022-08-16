#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

string a,c;
int b,d;
int dp[10205][105];

int calc(int x,int y){
	if(y==sz(c))return 0;
	if(x==10200)return M;
	int &ans=dp[x][y];
	if(ans!=-1)return ans;
	ans=1+calc(x+1,y);
	if(a[x%sz(a)]==c[y])ans=min(ans,1+calc(x+1,y+1));
	return ans;
}

int r[105];
int s[105];
void solve(){
	cin>>b>>d>>a>>c;
	int l=sz(a)*b;
	mem1(dp);
	mem1(r);
	int p=0,op=0,z=0;
	while(1){
		r[p]=op;
		s[p]=z;
		int k=calc(p,0);
		if(k>=M){
			cout<<0;
			return;
		}
		op+=k;
		if(op>l)break;
		z++;
		p+=k;
		p%=sz(a);
		if(r[p]!=-1){
			int x=(op-r[p]),y=(z-s[p]);
			while(op+100000*x<l)op+=100000*x,z+=100000*y;
			while(op+10000*x<l)op+=10000*x,z+=10000*y;
			while(op+1000*x<l)op+=1000*x,z+=1000*y;
			while(op+100*x<l)op+=100*x,z+=100*y;
			while(op+x<=l)op+=x,z+=y;
		}
	}
	cout<<z/d;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}