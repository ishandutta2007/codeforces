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
const int MAXN=30;
int T,n,f[MAXN][MAXN];
char s[MAXN]; 
int main(){
	cin>>T;
	while(T--){
		cin>>(s+1);n=strlen(s+1);
		memset(f,0,sizeof f);
		rep(i,1,n){
			if(s[i]=='a')f[i][i]=1;
		}
		rep(len,2,n){
			rep(i,1,n){
				int j=i+len-1;if(j>n)break;
				if(s[i]=='a'+len-1)f[i][j]|=f[i+1][j];
				if(s[j]=='a'+len-1)f[i][j]|=f[i][j-1];
			}
		} 
		if(f[1][n])printf("yes\n");
		else printf("no\n");
	}

	return 0;
}