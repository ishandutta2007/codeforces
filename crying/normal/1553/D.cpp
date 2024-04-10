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
const int MAXN=1e5+10;
ll T,n,m;
ll f[MAXN][2],nxt[MAXN][26][2];
char s[MAXN],t[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>(s+1)>>(t+1);
		n=strlen(s+1),m=strlen(t+1);
		rep(i,0,n+1){
			f[i][0]=f[i][1]=n+1;
			rep(j,0,25){
				nxt[i][j][0]=nxt[i][j][1]=n+1;
			}
		}
		if(n<m){
			printf("NO\n");
			continue;
		}
		per(i,n,1){
			rep(j,0,25){
				nxt[i][j][0]=nxt[i+1][j][0];
				nxt[i][j][1]=nxt[i+1][j][1];
			}
			nxt[i][s[i]-'a'][odd(i)]=i;
		}
		rep(i,1,n){
			if(s[i]==t[1]){
				if(odd(i) && f[1][1]==n+1){
					f[1][1]=i;
				}
				if(even(i) && f[1][0]==n+1){
					f[1][0]=i;
				}
			}
		}
		rep(i,1,m-1){
			if(f[i][0]!=n+1){
				f[i+1][1]=Min(f[i+1][1],nxt[f[i][0]][t[i+1]-'a'][1]);
			}
			if(f[i][1]!=n+1){
				f[i+1][0]=Min(f[i+1][0],nxt[f[i][1]][t[i+1]-'a'][0]);
			}
		}
		if(even(n)){
			if(f[m][0]!=n+1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			if(f[m][1]!=n+1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}

	return 0;
}