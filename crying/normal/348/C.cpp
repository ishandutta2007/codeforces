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
const int MAXN=1e5+10,MAXM=360,lim=350;
int n,m,q,num[MAXN],idx[MAXN],cnt[MAXN][MAXM];
ll ans[MAXN],tag[MAXN]; 
bool occ[MAXN][MAXM];
vector<int>s[MAXN];
char op;
int k,x;
ll a[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,m){
		int sz;scanf("%d",&sz);
		s[i].pb(sz);
		rep(j,1,sz){
			int tmp;scanf("%d",&tmp);
			s[i].pb(tmp);
		}
		if(sz>lim){
			num[++num[0]]=i,idx[i]=num[0];
			rep(j,1,sz)occ[s[i][j]][num[0]]=1;
		}
	}
//	printf("TMP:%d %d\n",occ[2][2],occ[5][2]);
	rep(i,1,m){
		rep(j,1,s[i][0]){
			ans[i]+=a[s[i][j]];
		//	printf("i:%d %d\n",i,s[i][j]);
			rep(k,1,num[0]){
				if(occ[s[i][j]][k])cnt[i][k]++;
			}
		}
	}
	rep(i,1,n)a[i]=0;
	rep(i,1,q){
		scanf(" %c",&op);
		if(op=='?'){
			scanf("%d",&k);
			ll ret=ans[k];
			if(s[k][0]<=lim){
				//
				rep(j,1,num[0]){
					ret+=tag[j]*cnt[k][j];
				}
				rep(j,1,s[k][0]){
					ret+=a[s[k][j]];
				}
			}
			printf("%I64d\n",ret);
		}else{
			scanf("%d%d",&k,&x);
			if(s[k][0]<=lim){
				// 
				rep(j,1,s[k][0]){
					a[s[k][j]]+=x;
				}
			}else{
				// 
				tag[idx[k]]+=x;
			}
			rep(j,1,num[0]){
		//		printf("j:%d %d %d\n",j,cnt[k][j],x);
				ans[num[j]]+=(ll)cnt[k][j]*x;
			}
		}
	}
	return 0;
}