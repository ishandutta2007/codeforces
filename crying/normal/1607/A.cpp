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
const int MAXN=1010,MAXM=30;
int T,n;
char s[MAXN];
int pos[MAXN];
int main(){
	cin>>T;
	while(T--){
		rep(i,1,26){
			char ch;
			cin>>ch;
			pos[(int)ch]=i;
		}
		cin>>(s+1);n=strlen(s+1);
		int ans=0;
		rep(i,2,n){
			ans+=abs(pos[(int)s[i]]-pos[(int)s[i-1]]);
		}
		printf("%d\n",ans);
	}

	return 0;
}