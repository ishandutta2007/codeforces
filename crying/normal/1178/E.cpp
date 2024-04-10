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
const int MAXN=1e6+10;
char s[MAXN];
vector<int>p;
int n,i,j;
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	i=1;j=n;
	while(i<=j){
		if(s[i]==s[j]){
			p.pb(i);if(i!=j)p.pb(j);
			i++;j--;
		}else if(s[i+1]==s[j]){
			i++;
		}else{
			j--;
		}
	}
	sort(p.begin(),p.end());
	int size=p.size();
	rep(k,0,size-1){
		printf("%c",s[p[k]]);
	}
	return 0;
}