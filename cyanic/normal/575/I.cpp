#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define clz __builtin_clz
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

const int N=5005,M=100005;
int op[M],d[M],x[M],y[M],len[M],ans[M],n,Q;
struct bit{
	int a[N][N*2];
	#define lb(x) (x&(-x))
	void upd(int x,int y,int z){
		for(int i=x;i;i-=lb(i))
			for(int j=y;j;j-=lb(j))
				a[i][j]+=z;
	}
	void upd(int l,int r,int y,int z){
		l=max(l,1),r=min(r,n);
		y=max(y,0),y=min(y,2*n);
		upd(l-1,y,-z),upd(r,y,z);
	}
	int qry(int x,int y){
		int res=0;
		for(int i=x;i<=n;i+=lb(i))
			for(int j=y;j<=n*2;j+=lb(j))
				res+=a[i][j];
		return res;
	}
}A,B;

int main(){
	read(n),read(Q);
	rep(i,1,Q){
		read(op[i]);
		if(op[i]==1){
			read(d[i]),read(x[i]);
			read(y[i]),read(len[i]);
		}
		else{
			read(x[i]),read(y[i]);
		}
	}
	rep(i,1,Q)
		if(op[i]==1&&d[i]==1){
			A.upd(x[i],x[i]+len[i],y[i]-1,-1);
			B.upd(x[i],x[i]+len[i],x[i]+y[i]+len[i],1);
		}
		else if(op[i]==1&&d[i]==4){
			A.upd(x[i]-len[i],x[i],y[i],1);
			B.upd(x[i]-len[i],x[i],x[i]+y[i]-len[i]-1,-1);
		}
		else if(op[i]==2){
			ans[i]+=A.qry(x[i],y[i]);
			ans[i]+=B.qry(x[i],x[i]+y[i]);
		}
	rep(i,1,Q)
		if(op[i]==1&&d[i]==1){
			A.upd(x[i],x[i]+len[i],y[i]-1,1);
			B.upd(x[i],x[i]+len[i],x[i]+y[i]+len[i],-1);
		}
		else if(op[i]==1&&d[i]==4){
			A.upd(x[i]-len[i],x[i],y[i],-1);
			B.upd(x[i]-len[i],x[i],x[i]+y[i]-len[i]-1,1);
		}
	rep(i,1,Q)
		if(op[i]==1&&d[i]==2){
			A.upd(x[i],x[i]+len[i],y[i],1);
			B.upd(x[i],x[i]+len[i],y[i]+(n+1-x[i])-len[i]-1,-1);
		}
		else if(op[i]==1&&d[i]==3){
			A.upd(x[i]-len[i],x[i],y[i]-1,-1);
			B.upd(x[i]-len[i],x[i],y[i]+(n+1-x[i])+len[i],1);
		}
		else if(op[i]==2){
			ans[i]+=A.qry(x[i],y[i]);
			ans[i]+=B.qry(x[i],y[i]+(n+1-x[i]));
		}
	rep(i,1,Q)
		if(op[i]==2) printf("%d\n",ans[i]);
	return 0;
}