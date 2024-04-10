#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#include<bits/stdc++.h>
const int N=2050;
using namespace std;

struct BIT{
	short a[N][N];
	BIT(){memset(a,0x3f,sizeof(a));}
	void add(int x,int y,short p){
		for(int i=x;i<N;i+=i&-i)
			for(int j=y;j<N;j+=j&-j)
				a[i][j]=min(a[i][j],p); 
	}
	short sum(int x,int y){
		short res=N*2;
		for(int i=x;i;i-=i&-i)
			for(int j=y;j;j-=j&-j)
				res=min(res,a[i][j]);
		return res;
	}
}A,B,C,D;

int n,k,a[N][N];
int px[N*N],py[N*N];
string res[N];

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j],px[a[i][j]]=i,py[a[i][j]]=j;
	for(int i=1;i<=n;i++)res[i].resize(n);
	for(int i=n*n;i;i--){
		int x=px[i],y=py[i];
		int a,b,c,d;
		a=x+y-A.sum(x,y);
		b=-x+y-B.sum(n-x+1,y);
		c=x-y-C.sum(x,n-y+1);
		d=-x-y-D.sum(n-x+1,n-y+1);
		int dis=max({a,b,c,d});
		if(dis>k)res[x][y-1]='G';
		else {
			res[x][y-1]='M';
			A.add(x,y,x+y);
			B.add(n-x+1,y,-x+y);
			C.add(x,n-y+1,x-y);
			D.add(n-x+1,n-y+1,-x-y);
		}
	}
	for(int i=1;i<=n;i++)cout<<res[i]<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}