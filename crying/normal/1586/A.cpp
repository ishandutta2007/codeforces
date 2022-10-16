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
int a[MAXN],t,n;
int check(int n){
	if(n==1)return 0;
	rep(i,2,n){
		if(i*i>n)break;
		if(n%i==0)return 0;
	}
	return 1;
}
void solve(){
	cin>>n;
	int cnt=0,flag=0;
	rep(i,1,n){
		cin>>a[i];
		cnt+=a[i];
		if(odd(a[i]))flag=i;
	}
	if(check(cnt)){
		printf("%d\n",n-1);
		rep(i,1,n){
		if(i!=flag)printf("%d ",i);
	}
	}else{
		printf("%d\n",n);
		rep(i,1,n)printf("%d ",i);
	}

		
	printf("\n");
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}