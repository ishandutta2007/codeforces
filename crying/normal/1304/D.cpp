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
const int MAXN=2e5+10;
int T,n,lim;
char s[MAXN];
void solve1(int start){
	if(start>n)return;
	int flag=0,cnt=0,mid=0;
	int end=start;
	while(end<n){
		if(s[end]=='<'){
			if(!mid)mid=end;
			flag=1;
		}else{
			if(flag)break;
		}
		end++;
	}
	cnt=end-start+1;
	if(!mid)mid=n;
	rep(x,start,mid){
		printf("%lld ",lim-cnt+(mid-x));
	}
	rep(x,mid+1,end){
		printf("%lld ",lim-(end-x+1));
	}
	lim-=cnt;
	solve1(end+1);
}
void solve2(int start){
	if(start>n)return;
	int flag=0,cnt=0,mid=0;
	int end=start;
	while(end<n){
		if(s[end]=='>'){
			if(!mid)mid=end;
			flag=1;
		}else{
			if(flag)break;
		}
		end++;
	}
	cnt=end-start+1;
	if(!mid)mid=n;
//	printf("[%d,%d](%d) ",start,end,mid);
	rep(x,start,mid){
		printf("%lld ",lim+cnt-(mid-x));
	}
	rep(x,mid+1,end){
		printf("%lld ",lim+(end-x+1));
	}
	lim+=cnt;
	solve2(end+1);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>(s+1);
		lim=n+1;
		solve1(1);printf("\n");
		lim=0;
		solve2(1);printf("\n");
	}

	return 0;
}