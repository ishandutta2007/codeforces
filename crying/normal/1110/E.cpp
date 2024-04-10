#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
int n,a[MAXN],b[MAXN],d1[MAXN],d2[MAXN];
map<int,int>f,g;
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
	}
	if(a[1]!=b[1]){
		printf("No");return 0;
	}
	rep(i,2,n){
		d1[i]=a[i]-a[i-1];
		d2[i]=b[i]-b[i-1];
		f[d1[i]]++;
		g[d2[i]]++;
	}
	rep(i,2,n){
		if(f[d1[i]]!=g[d1[i]]){
			printf("No");return 0;
		}
	}
	printf("Yes");
	return 0;
}