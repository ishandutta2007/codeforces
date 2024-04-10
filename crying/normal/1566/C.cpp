#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
ll t,n,ans;
char s[3][MAXN];
void solve(){
	cin>>n>>(s[1]+1)>>(s[2]+1);
	s[1][n+1]=s[2][n+1]=0;
	ans=0;
	rep(i,1,n){
		if(s[1][i]!=s[2][i]){
			ans+=2;continue;
		}
		if(s[1][i]=='1'){
			while(s[1][i]=='1' && s[2][i]=='1'){
				if(i>n)break;
				i++;
			}
			if(s[1][i]=='0' && s[2][i]=='0')ans+=2;
			else i--;
			continue;
		}
		if(s[1][i+1]=='1' && s[2][i+1]=='1'){
			ans+=2;i++;
		}else{
			ans++;
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		solve();
		printf("%lld\n",ans);
	}

	return 0;
}