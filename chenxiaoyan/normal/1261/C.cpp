/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n,m;
string a[N+1];
vector<int> Sum[N+1];
int sum(int b,int c,int d,int e){return Sum[d][e]-Sum[b-1][e]-Sum[d][c-1]+Sum[b-1][c-1];}
vector<int> d[N+1];
vector<int> now[N+2];
bool chk(int x){
	x=2*x+1;
//	cout<<x<<"\n";
	for(int i=0;i<=n+1;i++)d[i].clear(),d[i].resize(m+2,0);
	for(int i=1;i+x-1<=n;i++)for(int j=1;j+x-1<=m;j++)
		if(sum(i,j,i+x-1,j+x-1)==x*x)
			d[i+x][j+x]++,d[i][j+x]--,d[i+x][j]--,d[i][j]++;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)now[i][j]=now[i-1][j]+now[i][j-1]-now[i-1][j-1]+d[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='X'&&!now[i][j])return false;
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]=(string)" "+a[i];
	for(int i=0;i<=n;i++)Sum[i].resize(m+1),now[i].resize(m+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+(a[i][j]=='X');
	int ans=0;
	for(int i=20;~i;i--)if(chk(ans+(1<<i)))ans+=1<<i;
	ans=2*ans+1;
	cout<<ans/2<<"\n";
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]='.';
	for(int i=1;i+ans-1<=n;i++)for(int j=1;j+ans-1<=m;j++)
		if(sum(i,j,i+ans-1,j+ans-1)==ans*ans)
			a[i+i+ans-1>>1][j+j+ans-1>>1]='X';
	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<a[i][j];puts("");}
	return 0;
}
/*1
3 6
XXXXXX
XXXXXX
XXXXXX
*/