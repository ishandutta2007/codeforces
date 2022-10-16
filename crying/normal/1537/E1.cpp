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
const int MAXN=5e3+10;
int n,k,len,pos;
char S[MAXN];
char s[MAXN][MAXN];
int main(){
	cin>>n>>k>>S+1;
	pos=1;
	rep(i,1,n){
		//i 
		rep(j,1,k){
			s[i][j]=S[(j%i)?j%i:i];
		}
		if(i==1)continue;
		if(strcmp(s[i]+1,s[pos]+1)<0){
			pos=i;
		}
	}
	printf("%s",s[pos]+1);
	return 0;
}