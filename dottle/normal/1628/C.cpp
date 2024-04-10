#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

int n;
int A[N][N],v[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int p;

bool il(int x,int y){
	if(x<=0||y<=0||x>n||y>n)return 1;
	return v[x][y];
}

void go(int&x,int&y){
//	cout<<x<<' '<<y<<endl;
	int tx=x+dx[p],ty=y+dy[p];
	if(il(tx,ty))p=(p+1)%4;
	x=x+dx[p],y=y+dy[p];
}

void solve(){
	cin>>n;
	p=0;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			v[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>A[i][j];
	int x=1,y=1,ans=0; 
	while(!il(x,y)){
		int a,b,c,d;
		ans^=A[x][y];a=x,b=y;go(x,y);
		ans^=A[x][y];c=x,d=y;go(x,y);
		go(x,y);go(x,y);
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++) 
				v[a+i][b+j]=v[c+i][d+j]=1;
	}
	cout<<ans<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}