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
const int MAXN=32;
ll T,n,m,digit[MAXN],digit2[MAXN],ret[MAXN],ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		m++;
		ll nn=n,mm=m;
		rep(i,0,30){
			digit[i]=nn&1;
			digit2[i]=mm&1;
			nn>>=1;mm>>=1;
		}
		int flag=0;
		per(i,30,0){
			//00 
			if(flag){
				ret[i]=0;
				continue;
			}
			if(digit[i]>digit2[i]){
				ret[i]=0;
				flag=1;
				continue;
			}
			if(digit[i]==digit2[i]){
				ret[i]=0;
				continue;
			}
			ret[i]=1;
		}
		ans=0;
		rep(i,0,30){
			if(ret[i])ans|=(1<<i);
		}
		cout<<ans<<endl;
	}
	

	return 0;
}