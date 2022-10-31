#include<bits/stdc++.h>
//#define int long long
const int N=45;
using namespace std;

int n,a[N],A,B,f[N][N][N][N],pA[N],pB[N];
struct node{
	int i,j,x,y;char C;
}p[N][N][N][N];

void print(int i,int j,int x,int y){
	if(!i)return;
	node o=p[i][j][x][y];
	cout<<o.C;
	print(o.i,o.j,o.x,o.y);
}

void solve(){
	memset(f,0,sizeof(f));
	cin>>n>>A>>B;
	for(int i=n;i>=1;i--)
		scanf("%1d",&a[i]);
	pA[0]=1,pB[0]=1;
	for(int i=1;i<=n;i++)
		pA[i]=pA[i-1]*10%A,
		pB[i]=pB[i-1]*10%B;
	f[0][0][0][0]=1;
	for(int i=0;i<=n;i++)	
		for(int j=0;j<=n;j++)
			for(int x=0;x<A;x++)
				for(int y=0;y<B;y++)
					if(f[i][j][x][y]){
						f[i+1][j+1][(x+pA[j]*a[i+1])%A][y]=1;
						p[i+1][j+1][(x+pA[j]*a[i+1])%A][y]={i,j,x,y,'R'};
						f[i+1][j][x][(y+pB[i-j]*a[i+1])%B]=1;
						p[i+1][j][x][(y+pB[i-j]*a[i+1])%B]={i,j,x,y,'B'};
					}
	int ans=1e9;
	for(int x=n/2,y=n-x;x>0&&y<n;x--,y++){
		if(f[n][x][0][0]){
			print(n,x,0,0);
			cout<<endl;return;
		}
		if(f[n][y][0][0]){
			print(n,y,0,0);
			cout<<endl;return;
		}
	}
	cout<<-1<<endl;
}

int main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}