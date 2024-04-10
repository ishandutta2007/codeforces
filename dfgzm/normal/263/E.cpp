#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1010;
int i,j,k,n,m,a[maxn][maxn],shu[maxn][maxn],heng[maxn][maxn],xie1[maxn][maxn],xie2[maxn][maxn];
/*
1 2
 O
*/
ll ans=0,X1,Y1;
ll get(){
	ll Sum=0;
	for(i=1;i<=k;i++)
		for(j=k-i+1;j<=k;j++)
			Sum+=a[i][j];
	for(i=k+1;i<=2*k-1;i++)
		for(j=i-k+1;j<=k;j++)
			Sum+=a[i][j];
	return Sum;
}
ll get2(){
	ll Sum=0;
	for(i=1;i<=k;i++)
		for(j=k;j<=k+i-1;j++)
			Sum+=a[i][j];
	for(i=k+1;i<=2*k-1;i++)
		for(j=k;j<=3*k-i-1;j++)
			Sum+=a[i][j];
	return Sum;
}
ll get3(int x,int y){
	ll Sum=0;
	for(int i=x-k+1;i<=x+k-1;i++)
		for(int j=y-k+1;j<=y+k-1;j++){
			Sum+=a[i][j]*max(0,k-abs(i-x)-abs(j-y));
		}
	return Sum;
}
int main(){
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]),
			shu[i][j]=shu[i-1][j]+a[i][j],
			heng[i][j]=heng[i][j-1]+a[i][j],
			xie1[i][j]=xie1[i-1][j-1]+a[i][j],
			xie2[i][j]=xie2[i-1][j+1]+a[i][j];
	ll R1=get(),R2=get2(),lastans=get3(k,k);
//	cout<<R1<<' '<<R2<<endl;
	ans=-1;
	for(i=k;i<=n-k+1;i++){
		if(lastans>ans)ans=lastans,X1=i,Y1=k;
//		cout<<"----------------------"<<endl; 
//		cout<<"i="<<i<<" j="<<k<<" ans="<<lastans<<' '<<R1<<' '<<R2<<endl;
		ll r1=R1,r2=R2;
		for(j=k;j<=m-k;j++){
			R2=R2-(shu[i+k-1][j]-shu[i-k][j])+(xie2[i+k-1][j+1]-xie2[i-1][j+k+1])+(xie1[i-1][j+k-1]-xie1[i-k][j]);
			lastans=lastans+R2-R1;
//			cout<<"..... "<<(shu[i+k-1][j]-shu[i-k][j])<<endl;
			R1=R1+(shu[i+k-1][j+1]-shu[i-k][j+1])-(xie1[i+k-1][j]-xie1[i-1][j-k])-(xie2[i-1][j-k+2]-xie2[i-k][j+1]);
//			cout<<"i="<<i<<" j="<<j+1<<" ans="<<lastans<<' '<<R1<<' '<<R2<<endl;
//			cout<<i-1<<' '<<j-k+2<<' '<<i-k<<' '<<j+1<<' '<<(xie2[i-1][j-k+2]-xie2[i-k][j+1])<<endl;
			if(lastans>ans)ans=lastans,X1=i,Y1=j+1;
		}
//		cout<<"i="<<i<<" j="<<j<<" ans="<<lastans<<' '<<R1<<' '<<R2<<endl;
//		cout<<xie2[i+k][k]<<' '<<xie2[i][2*k]<<' '<<xie1[i][2*k-1]<<" "<<xie1[i-k][k-1]<<endl;
		R1=r1-(xie2[i][1]-xie2[i-k][k+1])+(xie1[i+k][k]);
		R2=r2+(xie2[i+k][k]-xie2[i][2*k])-(xie1[i][2*k-1]-xie1[i-k][k-1]);
		lastans=get3(i+1,k);
	}cout<<X1<<' '<<Y1<<endl;
	return 0;
}
/*
16 20 3
0 0 1 0 1 0 0 1 1 1 1 1 0 0 1 1 0 0 0 1
0 1 1 0 0 1 0 0 0 1 1 0 1 1 1 0 0 0 1 1
0 1 0 1 1 1 0 1 0 0 0 0 1 1 1 0 0 0 1 1
1 0 1 1 1 1 0 1 0 1 1 1 1 0 1 1 0 0 1 0
0 0 0 0 1 1 1 1 1 1 1 1 1 0 1 0 1 1 1 0
1 1 1 0 0 0 1 0 0 0 0 1 0 1 0 1 1 1 0 0
0 1 0 1 1 0 0 0 1 0 1 0 0 0 1 1 1 0 1 1
1 1 0 0 0 0 1 0 1 1 0 0 0 1 0 0 1 1 1 0
0 0 1 0 0 1 1 0 1 1 0 1 1 0 0 0 1 0 0 0
0 1 0 0 0 0 0 1 0 0 0 1 1 0 1 0 1 0 0 0
1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1 1 0 0 0
1 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 1 1 0 1 1 0 0 0 1 1 0 1 0 1 1 0
0 1 1 1 1 1 0 0 1 1 1 1 0 0 0 1 1 0 1 1
1 1 1 0 1 0 1 0 1 1 1 1 0 1 1 1 0 0 0 0
0 1 1 1 1 0 1 1 1 0 0 0 0 1 0 0 1 0 1 0
*/