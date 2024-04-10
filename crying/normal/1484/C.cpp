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
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int T,n,m,k,f,t[MAXN],t2[MAXN],ans[MAXN];
vector<int>v[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		rep(i,1,n)t[i]=t2[i]=0;
		rep(i,1,m){
			ans[i]=0;
			v[i].clear();
			cin>>k;
			rep(j,1,k){
				cin>>f;
				v[i].pb(f);
				t2[f]++;
			}
		}
		rep(i,1,m){
			int size=v[i].size();
			rep(j,0,size-1){
				if(t2[v[i][j]]<=(m+1)/2){
					ans[i]=v[i][j];
					t[v[i][j]]++;
					break;
				}
			}
		}
		rep(i,1,m){
			if(ans[i])continue;
			if(v[i].size()==1){
				ans[i]=v[i][0];
				t[v[i][0]]++;
			}
		}
		rep(i,1,m){
			if(ans[i])continue;
			int pos=v[i][0],size=v[i].size();
			rep(j,1,size-1){
				if(t[pos]>t[v[i][j]])pos=v[i][j];
			}
			ans[i]=pos;
			t[pos]++;
		}
		rep(i,1,n)if(t[i]>(m+1)/2)goto FAIL;
		printf("YES\n");
		rep(i,1,m)printf("%d ",ans[i]);printf("\n");
		continue;
		FAIL:printf("NO\n");
	}
	return 0;
}