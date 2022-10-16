#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=15;
int T,ans;
char s[MAXN];
void dfs(int r,int a,int b){
	if(r>10){return;}
	int resta=(bool)(1>=r)+(bool)(3>=r)+(bool)(5>=r)+(bool)(7>=r)+(bool)(9>=r);
	int restb=(bool)(2>=r)+(bool)(4>=r)+(bool)(6>=r)+(bool)(8>=r)+(bool)(10>=r);
	if(a+resta<b || b+restb<a){
		ans=min(ans,r-1);
		return;
	}
	if(s[r]=='1'){
		if(odd(r))dfs(r+1,a+1,b);
		else dfs(r+1,a,b+1);
	}else if(s[r]=='0'){
		dfs(r+1,a,b);
	}else{
		if(odd(r)){
			dfs(r+1,a+1,b);
		}else{
			dfs(r+1,a,b+1);
		}
		dfs(r+1,a,b);
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>(s+1);ans=10;
		dfs(1,0,0);
		printf("%d\n",ans);
	}

	return 0;
}