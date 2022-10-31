#include<bits/stdc++.h>
const int N=500050,P=20;
using namespace std;

int n,a[N],pr[N],mn[P][N],mx[P][N],ln[N];

int gi(int x,int y){
	int z=ln[y-x+1];
	return min(mn[z][x],mn[z][y-(1<<z)+1]);
}
int gx(int x,int y){
	int z=ln[y-x+1];
	return max(mx[z][x],mx[z][y-(1<<z)+1]);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],pr[a[i]]=mn[0][pr[a[i]]]=i;
	ln[0]=-1;
	for(int i=1;i<=n;i++)
		mx[0][i]=a[i],mn[0][pr[a[i]]]=n+1,ln[i]=ln[i>>1]+1;
	for(int i=1;i<P;i++)
		for(int j=1;j<=n-(1<<i)+1;j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]),
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i,mx=0;j<=n;){
			if(gi(i,j)<=j)break;
			mx=gx(i,j);
			if(mx==j-i+1)ans++,j++;
			else j=i+mx-1;
		}
	}
	cout<<ans;
}