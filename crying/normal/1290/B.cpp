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
int Q,n,l,r;
int sum[26][MAXN];
char s[MAXN]; 
int main(){
	cin>>(s+1);n=strlen(s+1);	
	rep(i,1,n){
		rep(j,0,25)sum[j][i]=sum[j][i-1];
		sum[s[i]-'a'][i]++;
	}
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		if(s[l]!=s[r] || l==r){
			printf("Yes\n");
			continue;
		}
		int cnt=0;
		rep(j,0,25){
			if(sum[j][r]!=sum[j][l-1]){
				cnt++;
			}
		}
		if(cnt>=3)printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}