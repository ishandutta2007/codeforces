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
const int MAXN=2e5+10;
int T,n,a[MAXN];
char s[MAXN]; 
vector<int>L,R;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		cin>>(s+1);
		L.clear();R.clear();
		rep(i,1,n){
			if(s[i]=='B')L.pb(a[i]);
			else R.pb(a[i]); 
		}
		sort(L.begin(),L.end());
		sort(R.begin(),R.end(),greater<int>());
		int sz=L.size();
		int flag=1;
		rep(i,0,sz-1){
			if(L[i]<i+1)flag=0;
		}
		rep(i,0,(int)R.size()-1){
			if(R[i]>n-i)flag=0;
		}
		if(flag)printf("YES\n");
		else printf("NO\n"); 
	}

	return 0;
}