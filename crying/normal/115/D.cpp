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
const int MAXN=2010,moder=1e6+3;
ll f[MAXN][MAXN],ans; 
int n;
char s[MAXN];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	// 
	rep(i,1,n){
		if(s[i]>='0' && s[i]<='9')continue;
		if(i==n)return printf("0"),0;
		if((s[i]=='*' || s[i]=='/') && (s[i-1]<'0' || s[i-1]>'9'))return printf("0"),0;
	}
	f[0][0]=1;
	int i=0;
	while(i<=n){
		//
		//
		rep(j,0,n-1)f[i][j+1]=(f[i][j+1]+f[i][j])%moder;
		if(s[i+1]>='0' && s[i+1]<='9'){
			int len=0;
			rep(j,i+1,n){
				if(s[j]>='0' && s[j]<='9')len++;
				else break;
			} 
			if(i+len==n){
				//
				return printf("%lld",f[i][0]),0;
			}
			rep(j,0,n-1){
				f[i+len+1][j]=(f[i+len+1][j]+f[i][j+1])%moder;
			}
			i=i+len+1;
			continue;
		}
		//
		rep(j,0,n)f[i+1][j]=(f[i+1][j]+f[i][j])%moder;
		i++;
	}
	return 0;
}