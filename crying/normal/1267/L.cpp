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
const int MAXN=1010,MAXM=1e6+10;
int n,k,l,bucket[26];
char s,ret[MAXN][MAXN];
int main(){
	cin>>n>>l>>k;
	rep(i,1,n*l){
		cin>>s;
		bucket[s-'a']++;
	}
	int L=0;
	rep(i,1,l){
	//	printf("i:%d L:%d\n",i,L);
		per(x,n,1){if(x>L && x<=k)continue;
		//	printf("x:%d\n",x);
			per(j,25,0){
				if(bucket[j]){
					ret[x][i]='a'+j;
					bucket[j]--;
					break;
				}
			}
		}
		//printf("i:%d %d\n",i,L);
		rep(j,0,25){
			if(bucket[j]>=k-L){
				rep(x,L+1,k){
					ret[x][i]='a'+j;
				}
				bucket[j]-=(k-L);
				break;
			}else{
				rep(x,L+1,L+bucket[j]){
					ret[x][i]='a'+j;
				}
				L+=bucket[j];
				bucket[j]=0;
			}
		}
	}
	rep(i,1,n){
		printf("%s\n",ret[i]+1);
	}
	return 0;
}