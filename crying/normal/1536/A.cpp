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
const int MAXN=310;
map<ll,int>f;
int T,n,a[MAXN],k,b[MAXN];
queue<int>q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		f.clear();
		while(q.size())q.pop();
		k=0;
		rep(i,1,n)scanf("%d",&a[i]),f[a[i]]=1,b[++k]=a[i],q.push(a[i]);
		int flag=1;
		while(q.size()){
			int u=q.front();q.pop();
			rep(j,1,k){
				ll d=abs(b[j]-u);
				if(d==0)continue;
				if(f[d])continue;
				f[d]=1;
				b[++k]=d;
				q.push(d);
				if(k>300){
					flag=0;break;
				}
			}
			if(flag==0)break;
		}
		if(flag==0){
			printf("NO\n");
		}else{
			printf("YES\n");
			printf("%d\n",k);
			rep(i,1,k)printf("%d ",b[i]);
			printf("\n");
		}
		
	}

	return 0;
}