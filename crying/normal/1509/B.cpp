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
const int MAXN=1e5+10;
int T,n,cnt1,cnt2,flag;
char str[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>str+1;
		cnt1=cnt2=0;
		rep(i,1,n){
			if(str[i]=='T')cnt1++;
			else cnt2++;
		}
		if(cnt2*2!=cnt1){
			printf("NO\n");continue;
		}
		cnt1=0;cnt2=0;flag=1;
		rep(i,1,n){
			if(str[i]=='T')cnt1++;
			else{
				cnt2++;
				if(cnt1<cnt2){
					printf("NO\n");flag=0;break;
				}
			}
		}
		if(!flag)continue;
		cnt1=0;cnt2=0;
		per(i,n,1){
			if(str[i]=='T')cnt1++;
			else{
				cnt2++;
				if(cnt1<cnt2){
					printf("NO\n");flag=0;break;
				}
			}
		}
		if(flag)printf("YES\n");
	}

	return 0;
}