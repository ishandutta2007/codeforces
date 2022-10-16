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
const int MAXN=3e5+10;
char s[MAXN];
int n,t;
int main(){
	cin>>t;
	while(t--){
		cin>>s+1;n=strlen(s+1);
		int flag=1;
		rep(i,1,n)if(s[i]!='a')flag=0;
		if(flag){
			printf("NO\n");continue;
		} 
		rep(i,1,n){
			int oth=n-i+1;
			if(s[i]=='a')continue;
			printf("YES\n");
			rep(j,1,oth)printf("%c",s[j]);
			printf("a");
			rep(j,oth+1,n)printf("%c",s[j]);
			printf("\n");
			goto END;
		}
		printf("NO\n");continue;
		END:;
	}
	return 0;
}