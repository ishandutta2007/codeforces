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
const int MAXN=5e4+10,MAXM=10;
int T,n,r[MAXN][MAXM],ret,retval,ans;
vector<int>s[MAXM];
int check(int pos){
	rep(i,1,n){
		int num=0;
		rep(j,1,5){
			if(r[i][j]>=r[pos][j])num++;
		}
		if(num<3)return 0;
	}
	return 1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(j,1,5)s[j].clear();
		rep(i,1,n){
			rep(j,1,5){
				cin>>r[i][j];
			}
		}
		int ans=1;
		rep(i,2,n){
			int cnt=0;
			rep(j,1,5){
				if(r[i][j]<r[ans][j])cnt++; 
			}
			if(cnt>=3){
				ans=i;
			}
		}
		int flag=1;
		rep(i,1,n){
			int cnt=0;
			rep(j,1,5){
				if(r[i][j]>=r[ans][j])cnt++;
			}
			if(cnt<3){
				flag=0;break;
			}
		}
		if(flag)printf("%d\n",ans);
		else printf("%d\n",-1);
	}

	return 0;
}