#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define X first
#define Y second
const int N=1000,M=1000;
int n,m,s;
int a[N+1][M+1];
int Sum1[M+1][N+1],Sum2[N+M+1][M+1],Sum3[2*N+1][M+1];
int sum1(int x,int l,int r){return l>r?0:Sum1[x][r]-Sum1[x][l-1];}
int sum2(int x,int l,int r){return l>r?0:Sum2[x][r]-Sum2[x][l-1];}
int sum3(int x,int l,int r){return l>r?0:Sum3[x+max(n,m)][r]-Sum3[x+max(n,m)][l-1];}
int trl[N+1][M+1],trr[N+1][M+1];
int rhm[N+1][M+1];
signed main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%lld",a[i]+j);
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)Sum1[i][j]=Sum1[i][j-1]+a[j][i];
	for(int i=1;i<=n+m;i++)for(int j=1;j<=n;j++)Sum2[i][j]=Sum2[i][j-1]+(1<=i-j&&i-j<=m?a[j][i-j]:0);
	for(int i=-max(n,m);i<=max(n,m);i++)for(int j=1;j<=n;j++)Sum3[i+max(n,m)][j]=Sum3[i+max(n,m)][j-1]+(1<=j+i&&j+i<=m?a[j][j+i]:0);
	for(int i=s;i<=n-s+1;i++){
		for(int j=1;j<=s;j++)trl[i][s]+=sum1(j,i-j+1,i+j-1);
		for(int j=s+1;j<=m;j++)trl[i][j]=trl[i][j-1]+sum1(j,i-s+1,i+s-1)-sum2(i+j-s,i-s+1,i)-sum3(j-s-i,i+1,i+s-1);
	}
	for(int i=s;i<=n-s+1;i++){
		for(int j=m;j>=m-s+1;j--)trr[i][m-s+1]+=sum1(j,i-(m-j+1)+1,i+(m-j+1)-1);
		for(int j=m-s;j;j--)trr[i][j]=trr[i][j+1]+sum1(j,i-s+1,i+s-1)-sum3(j+s-i,i-s+1,i)-sum2(i+j+s,i+1,i+s-1);
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)printf("tr(%lld,%lld)=(%lld,%lld)\n",i,j,trl[i][j],trr[i][j]);
	for(int i=s;i<=n-s+1;i++){
		for(int j=0;j<s;j++)rhm[i][s]+=(s-j)*(sum2(i-j+s,i-j,i)+sum3(s-(i+j),i+1,i+j)+sum2(i+j+s,i,i+j-1)+sum3(s-(i-j),i-j+1,i-1));
		for(int j=s+1;j<=m-s+1;j++)rhm[i][j]=rhm[i][j-1]+trr[i][j]-trl[i][j-1];
	}
//	for(int i=s;i<=n-s+1;i++)for(int j=s;j<=m-s+1;j++)printf("rhm[%lld][%lld]=%lld\n",i,j,rhm[i][j]);
	pair<int,pair<int,int> > mx(0,mp(0,0));
	for(int i=s;i<=n-s+1;i++)for(int j=s;j<=m-s+1;j++)mx=max(mx,mp(rhm[i][j],mp(i,j)));
	cout<<mx.Y.X<<" "<<mx.Y.Y;
	return 0;
}
/*1
4 4 2
1 2 3 4
1 1 1 1
2 2 2 2
4 3 2 1
*/
/*2
5 7 3
8 2 3 4 2 3 3
3 4 6 2 3 4 6
8 7 6 8 4 5 7
1 2 3 2 1 3 2
4 5 3 2 1 2 1
*/