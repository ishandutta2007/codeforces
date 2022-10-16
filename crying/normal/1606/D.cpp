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
const int MAXN=5e5+10,INF=1e9;
int T,n,m;
vector<int>a[MAXN];
vector<pi>lim[2][MAXN];
int bucket[MAXN];
struct BIT{
	int tree[MAXN*2];
	void update(int x,int val){
		for(;x<=1e6;x+=lowbit(x))tree[x]+=val;
	}
	void clr(int x){
		for(;x<=1e6;x+=lowbit(x))tree[x]=0;
	}
	int query(int x){
		int ret=0;
		for(;x;x-=lowbit(x))ret+=tree[x];
		return ret;
	}
	int getkth(int k){
		int L=1,R=1e6,ret=0;
		while(L<=R){
			int mid=(L+R)>>1;
			if(query(mid)>=k){
				ret=mid;
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		return ret;
	}
}l,r;
struct Node{
	int r,maxn,minn;
	bool operator<(const Node& n2)const{
		return maxn>n2.maxn;
	}
}rows[MAXN];
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)bucket[i]=0;
	rep(i,1,n){
		a[i].resize(m+5);
		lim[0][i].resize(m+5);
		lim[1][i].resize(m+5); 
	}
	rep(i,1,n){
		rep(j,1,m){
			scanf("%d",&a[i][j]);
		}
		lim[0][i][0]=mp(INF,-INF);
		lim[1][i][m+1]=mp(INF,-INF);
		rep(j,1,m){
			lim[0][i][j].fr=min(lim[0][i][j-1].fr,a[i][j]);
			lim[0][i][j].se=max(lim[0][i][j-1].se,a[i][j]);
		}
		per(j,m,1){
			lim[1][i][j].fr=min(lim[1][i][j+1].fr,a[i][j]);
			lim[1][i][j].se=max(lim[1][i][j+1].se,a[i][j]);
		}
	}
	rep(i,1,n)rep(j,1,m)r.update(a[i][j],1);
	rep(j,1,m-1){
		rep(i,1,n){
			rows[i].minn=lim[0][i][j].fr;
			rows[i].maxn=lim[0][i][j].se;
			rows[i].r=i;
		}
		sort(rows+1,rows+1+n);
		//move column j from r to l 
		rep(i,1,n){
			r.update(a[i][j],-1);
			l.update(a[i][j],1);
		}
		int num1=j,num2=m-j;
		int minn=INF,maxn=-INF,minr=INF,maxr=-INF;
		int L1,R1=l.getkth(num1*n),L2=r.getkth(1),R2;
		rep(i,1,n-1){
			//choose first i rows in left matrix
			minn=min(minn,rows[i].minn);
			maxn=max(maxn,rows[i].maxn);
			minr=min(minr,lim[1][rows[i].r][j+1].fr);
			maxr=max(maxr,lim[1][rows[i].r][j+1].se);
			L1=l.getkth(num1*(n-i)+1);
			R2=r.getkth(num2*i);
			if(L1==l.getkth(num1*(n-i)))continue;
			if(R2==r.getkth(num2*i+1))continue;
		//	printf("i:%d [%d,%d] [%d,%d]\n",i,L1,R1,L2,R2);
		//	printf("%d %d %d %d\n",minn,maxn,minr,maxr);
			if(minn==L1 && maxn==R1 && minr==L2 && maxr==R2){
				printf("YES\n");
				rep(k,1,i)bucket[rows[k].r]=1;
				rep(k,1,n){
					if(bucket[k])printf("R");
					else printf("B");
				}
				printf(" %d\n",j);
				goto END;
			}
		}
	}
	printf("NO\n");
	END:rep(i,1,n)rep(j,1,m)l.clr(a[i][j]),r.clr(a[i][j]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}
/*
1
4 2
8 3
7 9
7 8
8 5
*/