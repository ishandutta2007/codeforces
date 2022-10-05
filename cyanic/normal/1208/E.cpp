#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005;
int stk[N],lc[N],rc[N],a[N],top,n,w,l;
ll ans[N];

inline void add(int l,int r,int x){
	ans[l]+=x,ans[r+1]-=x;
	//printf("add %d %d %d\n",l,r,x);
}

void solve(int l,int r,int o,int len){
	if(l>r)return;
	int L=max(l,o),R=min(r,o+len-1);
	add(L,R,a[o]);
	if(lc[o]!=-1)solve(l,L-1,lc[o],len);
	if(rc[o]!=-1)solve(R+1,r,rc[o],len);
}

int main(){
	read(n),read(w);
	rep(i,1,n){
		read(l);
		top=0;
		rep(i,1,l)read(a[i]);
		a[0]=a[l+1]=0;
		rep(i,0,l+1)lc[i]=rc[i]=-1;
		rep(i,0,l+1){
			while(top>=2&&a[i]>a[stk[top-1]])
				rc[stk[top-1]]=stk[top],top--;
			if(top>=1&&a[i]>a[stk[top]])
				lc[i]=stk[top--];
			stk[++top]=i;
		}
		while(top>=2)
			rc[stk[top-1]]=stk[top],top--;
		solve(1,w,stk[top],w-l+1);
	}
	rep(i,1,w){
		ans[i]+=ans[i-1];
		printf("%lld ",ans[i]);
	}
	puts("");
	return 0;
}