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
const int MAXN=110;
int t,n,a[MAXN],cnt1,cnt2;
void solve(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){printf("1\n");return;}
	if(a[n]==2){printf("%d\n",1+(a[1]!=a[n]));return;}
	cnt1=cnt2=0;
	rep(i,1,n){
		if(a[i]%3==1)cnt1++;
		else if(a[i]%3==2)cnt2++; 
	}
	if(!cnt1 && !cnt2){
		printf("%d\n",a[n]/3);return;
	}
	if(!cnt1 || !cnt2){
		printf("%d\n",a[n]/3+1);
		return;
	}
	if(a[n]%3==0){
		printf("%d\n",(a[n]/3-1)+2);
		return;
	}
	if(a[1]!=1){
		int ret=0;
		rep(j,1,n){
			if(a[j]%3==1){
				ret=max(ret,a[j]/3-1);
			}else{
				ret=max(ret,a[j]/3);
			}
		}
		printf("%d\n",ret+2);
		return;
	}
	printf("%d\n",a[n]/3+2);
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}