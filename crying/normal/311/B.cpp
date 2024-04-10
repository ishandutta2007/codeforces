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
const int MAXN=1e5+10,MAXM=110;
ll n,m,p,d[MAXN],h[MAXN],t[MAXN],sumdis[MAXN];
ll sumt[MAXN],f[MAXN][MAXM];
ll q[MAXN],head,rear,ans;
void ins(int i,int j){
	while(rear-head>=2){
		int x=q[rear-2],y=q[rear-1],z=i;
		if(((f[y][j]+sumt[y])-(f[x][j]+sumt[x]))*(z-y) >= ((f[z][j]+sumt[z])-(f[y][j]+sumt[y]))*(y-x))rear--;
		else break;
	}
	q[rear++]=i;
}
void check(int j,ll val){
	while(rear-head>=2){
		int x=q[head],y=q[head+1];
		if(((f[y][j]+sumt[y])-(f[x][j]+sumt[x]))<val*(y-x))head++;
		else break;
	}	
}
int query(){
	return q[head];
}
int main(){
	cin>>n>>m>>p;
	rep(i,2,n){
		cin>>d[i];
		sumdis[i]=sumdis[i-1]+d[i];
	}
	rep(i,1,m){
		cin>>h[i]>>t[i];
		t[i]-=sumdis[h[i]]; //>=t[i] 
	}
	sort(t+1,t+1+m); // 
	rep(i,1,m)sumt[i]=sumt[i-1]+t[i];
	//
	rep(i,1,m){
		f[i][1]=i*t[i]-sumt[i];
	} 
	ans=f[m][1];
	rep(j,2,p){
		head=rear=1;
		ins(0,j-1);	
		rep(i,1,m){
			check(j-1,t[i]);
			int k=query();
			f[i][j]=f[k][j-1]+(i-k)*t[i]-sumt[i]+sumt[k];
			ins(i,j-1);
		}
		ans=Min(ans,f[m][j]);
	}
	cout<<ans;
	return 0;
}