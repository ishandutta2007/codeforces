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
ll t,n,m;
string str[MAXN],tmp[MAXN];
char ans[MAXN];
int bucket1[26],bucket2[26];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(ans,0,sizeof ans);
		rep(i,1,n){
			cin>>str[i];
		}
		rep(i,1,n-1){
			cin>>tmp[i];
		}
		rep(i,1,m){
			//i 
			rep(j,1,n){
				bucket1[str[j][i-1]-'a']++;
			}
			rep(j,1,n-1){
				bucket2[tmp[j][i-1]-'a']++;
			}
			rep(j,0,25){
				if(bucket2[j]!=bucket1[j]){
					ans[i]='a'+j;
					break;
				}
			}
			rep(j,1,n){
				bucket1[str[j][i-1]-'a']--;
			}
			rep(j,1,n-1){
				bucket2[tmp[j][i-1]-'a']--;
			}
		}
		printf("%s\n",ans+1); 
	}

	return 0;
}