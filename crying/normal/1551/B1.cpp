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
const int MAXN=60;
int T,n,ans,cnta,cntb;
char s[60],cnt[60];
int main(){
	cin>>T;
	while(T--){
		cin>>(s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		rep(i,1,n){
			cnt[s[i]-'a']++;
		}
		cnta=0;cntb=0;
		rep(i,0,25){
			if(cnt[i]==1){
				if(cnta<cntb)cnta++;
				else cntb++;
			}
		}
		rep(i,0,25){
			if(cnt[i]>1){
				cnta++;cntb++;
			}
		}
		printf("%d\n",min(cnta,cntb));
	}

	return 0;
}