#include <bits/stdc++.h>
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
#define ppc               __builtin_popcount

int arr[100005];

string s,t;
int sn,tn,dp[405][205][205];
char at[405][205][205];
int calc(int d,int x,int y){
	// cout<<d<<" "<<x<<" "<<y<<"\n";
	if(x==sn && y==tn) {
		if(d==0)return 0;
		// at[d][x][y]=1;return 1+calc(d-1,x,y);
	}
	int &ans=dp[d][x][y];
	if(ans!=-1)return ans;
	ans=M;
	if(d==0 || s[x]=='(' || t[y]=='('){
		ans=min(ans,calc(d+1,x+(s[x]=='('),y+(t[y]=='(')));
	}
	if(d && ((s[x]==')' || t[y]==')') || (x==sn && y==tn))){
		int tmp=calc(d-1,x+(s[x]==')'),y+(t[y]==')'));
		if(tmp<ans){
			ans=tmp;
			at[d][x][y]=1;
		}
	}
	ans++;
	return ans;
}
void solve(){
	mem1(dp);
	cin>>s>>t;
	sn=s.size();
	tn=t.size();
	s.pb('0');
	t.pb('0');
	int n=calc(0,0,0);
	// cout<<n<<"\n";
	int d=0,x=0,y=0;
	rep(i,0,n){
		if(at[d][x][y]){
			cout<<')';
			x+=s[x]==')';
			y+=t[y]==')';
			d--;
		}
		else{
			cout<<'(';
			x+=s[x]=='(';
			y+=t[y]=='(';
			d++;
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
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}