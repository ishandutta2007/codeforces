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
int t,n;
char a[MAXN],b[MAXN];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a+1>>b+1;
		int sum=0,flag1=0,flag2=0,cnt=0;
		rep(i,1,n){
			if(a[i]=='0')sum++;
			else sum--;
			if(a[i]==b[i])flag1=1;
			else flag2=1;
			if(sum==0){
				cnt++;
				if(flag1 && flag2)goto FAIL;
				flag1=0;flag2=0;
			}
		}
		if(flag2)goto FAIL;
		SUCCESS:printf("YES\n");continue;
		FAIL:printf("NO\n");continue;
	}
	return 0;
}