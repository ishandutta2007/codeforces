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
const int MAXN=120,ADD=100,INF=1e9;
int T,a[MAXN],l,r,n;
char s[MAXN];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	l=r=0;
	int cnt=1;
	rep(i,2,n){
		if(s[i]!=s[i-1]){
			cnt++;
		}
	}
	if(even(cnt)){
		int pre=1;
		rep(i,2,n){
			if(s[i]!=s[i-1]){
				if(r==0){
					l=pre;
					r=i-1;
				}else{
					if(r-l+1>i-pre){
						l=pre;r=i-1;
					}
				}
				pre=i;
			}
		}
		if(r-l+1>n-pre+1){
			l=pre;r=n;
		}
		if(s[1]==s[2]){
			l=1;r=1;
		}
		if(s[n-1]==s[n]){
			l=n;r=n;
		}
	}
	rep(i,l,r){
		if(s[i]=='a')s[i]='b';
		else s[i]='a';
	}
	printf("%s\n",s+1);
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}
					
	return 0;
}