#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,sumh[1010][1010][2],suml[1010][1010][2],map[1010][1010],val[1010][1010][2],ans[1010][1010],sumx[1010][1010];
void out()
{
	int ansx=K,ansy=K;
	for(int i=K;i<=n-K+1;++i)
	{
		for(int j=K;j<=m-K+1;++j)
		{
			if(ans[i][j]>ans[ansx][ansy])
				ansx=i,ansy=j;
			//cout<<ans[i][j]<<" ";
		}
		//cout<<endl;
	}
	/*memset(ans,0,sizeof(ans));
	for(int i=K;i<=n-K+1;++i)
	{
		for(int j=K;j<=m-K+1;++j)
		{
			int val=0;
			for(int k=1;k<=n;++k)
				for(int w=1;w<=m;++w)
					val+=map[k][w]*max(0,K-abs(i-k)-abs(j-w));
			cout<<val<<" ";
		}
		cout<<endl;
	}*/
	printf("%lld %lld\n",ansx,ansy);
}
signed main()
{
	//cout<<(sizeof(suml)+sizeof(sumh)+sizeof(map)+sizeof(sumx)+sizeof(ans)+sizeof(val))/1024/1024<<endl;
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			map[i][j]=read();
	//----------------------------right down 1
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
		{
			suml[i][j][0]=suml[i-1][j][0]+map[i][j];
			suml[i][j][1]=suml[i-1][j][1]+map[i][j]*i;
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			sumh[i][j][0]=sumh[i][j-1][0]+map[i][j];
			sumh[i][j][1]=sumh[i][j-1][1]+map[i][j]*j;
		}
	for(int p=2;p<=n+m;++p)
		for(int i=1;i<=n;++i)
			if(1<=p-i && p-i<=m)
				sumx[i][p-i]=sumx[i-1][p-i+1]+map[i][p-i];
	memset(val,0,sizeof(val));
	for(int i=1;i<=K;++i)
		for(int j=1;j<=K;++j) if(K-abs(K-i)-abs(K-j)>0)
		{
			val[K][K][0]+=map[i][j]*(K-abs(K-i)-abs(K-j));
			val[K][K][1]+=map[i][j];
		}
	ans[K][K]+=val[K][K][0];
	for(int i=K;i<=n-K+1;++i)
		for(int j=K;j<=m-K+1;++j)
		{
			if(i==K && j==K) continue;
			if(j==K)
			{
				val[i][j][0]=val[i-1][j][0]-val[i-1][j][1]+(sumh[i][j][1]-sumh[i][j-K][1])+(K-j)*(sumh[i][j][0]-sumh[i][j-K][0]);
				val[i][j][1]=val[i-1][j][1]-(sumx[i-1][j-K+1]-sumx[i-1-K+1][j])-map[i-1-K+1][j]+(sumh[i][j][0]-sumh[i][j-K][0]);
			}
			else
			{
				val[i][j][0]=val[i][j-1][0]-val[i][j-1][1]+(suml[i][j][1]-suml[i-K][j][1])+(K-i)*(suml[i][j][0]-suml[i-K][j][0]);
				val[i][j][1]=val[i][j-1][1]-(sumx[i][j-1-K+1]-sumx[i-K+1][j-1])-map[i-K+1][j-1]+(suml[i][j][0]-suml[i-K][j][0]);
			}
			ans[i][j]+=val[i][j][0];
		}
	//----------------------------right up 2
	--K;
	if(!K) {++K;out();return 0;}
	for(int j=1;j<=m;++j)
		for(int i=n;i>=1;--i)
		{
			suml[i][j][0]=suml[i+1][j][0]+map[i][j];
			suml[i][j][1]=suml[i+1][j][1]+map[i][j]*(n-i+1);
		}
	for(int p=2;p<=n+m;++p)
		for(int i=1;i<=n;++i)
			if(1<=p-i && p-i<=m)
				sumx[n-i+1][p-i]=sumx[n-i+2][p-i+1]+map[n-i+1][p-i];
	memset(val,0,sizeof(val));
	for(int i=n;i>=n-K+1;--i)
		for(int j=1;j<=K;++j) if(K-abs(n-K+1-i)-abs(K-j)>0)
		{
			val[n-K+1][K][0]+=map[i][j]*(K-abs(n-K+1-i)-abs(K-j));
			val[n-K+1][K][1]+=map[i][j];
		}
	ans[n-K][K]+=val[n-K+1][K][0];
	for(int i=n-K+1;i>=K;--i)
		for(int j=K;j<=m-K+1;++j)
		{
			if(i==n-K+1 && j==K) continue;
			if(j==K)
			{
				val[i][j][0]=val[i+1][j][0]-val[i+1][j][1]+(sumh[i][j][1]-sumh[i][j-K][1])+(K-j)*(sumh[i][j][0]-sumh[i][j-K][0]);
				val[i][j][1]=val[i+1][j][1]-(sumx[i+1][j-K+1]-sumx[i+1+K-1][j])-map[i+1+K-1][j]+(sumh[i][j][0]-sumh[i][j-K][0]);
			}
			else
			{
				val[i][j][0]=val[i][j-1][0]-val[i][j-1][1]+(suml[i][j][1]-suml[i+K][j][1])+(K-(n-i+1))*(suml[i][j][0]-suml[i+K][j][0]);
				val[i][j][1]=val[i][j-1][1]-(sumx[i][j-1-K+1]-sumx[i+K-1][j-1])-map[i+K-1][j-1]+(suml[i][j][0]-suml[i+K][j][0]);
			}
			ans[i-1][j]+=val[i][j][0];
		}
	//----------------------------left down 3
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
		{
			suml[i][j][0]=suml[i-1][j][0]+map[i][j];
			suml[i][j][1]=suml[i-1][j][1]+map[i][j]*i;
		}
	for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)
		{
			sumh[i][j][0]=sumh[i][j+1][0]+map[i][j];
			sumh[i][j][1]=sumh[i][j+1][1]+map[i][j]*(m-j+1);
		}
	for(int p=2;p<=n+m;++p)
		for(int i=1;i<=n;++i)
			if(1<=p-i && p-i<=m)
				sumx[i][m-(p-i)+1]=sumx[i-1][m-(p-i+1)+1]+map[i][m-(p-i)+1];
	memset(val,0,sizeof(val));
	for(int i=1;i<=K;++i)
		for(int j=m;j>=m-K+1;--j) if(K-abs(K-i)-abs(m-K+1-j)>0)
		{
			val[K][m-K+1][0]+=map[i][j]*(K-abs(K-i)-abs(m-K+1-j));
			val[K][m-K+1][1]+=map[i][j];
		}
	ans[K][m-K]+=val[K][m-K+1][0];
	for(int i=K;i<=n-K+1;++i)
		for(int j=m-K+1;j>=K;--j)
		{
			if(i==K && j==m-K+1) continue;
			if(j==m-K+1)
			{
				val[i][j][0]=val[i-1][j][0]-val[i-1][j][1]+(sumh[i][j][1]-sumh[i][j+K][1])+(K-(m-j+1))*(sumh[i][j][0]-sumh[i][j+K][0]);
				val[i][j][1]=val[i-1][j][1]-(sumx[i-1][j+K-1]-sumx[i-1-K+1][j])-map[i-1-K+1][j]+(sumh[i][j][0]-sumh[i][j+K][0]);
			}
			else
			{
				val[i][j][0]=val[i][j+1][0]-val[i][j+1][1]+(suml[i][j][1]-suml[i-K][j][1])+(K-i)*(suml[i][j][0]-suml[i-K][j][0]);
				val[i][j][1]=val[i][j+1][1]-(sumx[i][j+1+K-1]-sumx[i-K+1][j+1])-map[i-K+1][j+1]+(suml[i][j][0]-suml[i-K][j][0]);
			}
			ans[i][j-1]+=val[i][j][0];
		}
	//----------------------------left up 4
	--K;
	if(!K) {K+=2;out();return 0;}
	for(int j=1;j<=m;++j)
		for(int i=n;i>=1;--i)
		{
			suml[i][j][0]=suml[i+1][j][0]+map[i][j];
			suml[i][j][1]=suml[i+1][j][1]+map[i][j]*(n-i+1);
		}
	for(int p=2;p<=n+m;++p)
		for(int i=1;i<=n;++i)
			if(1<=p-i && p-i<=m)
				sumx[n-i+1][m-(p-i)+1]=sumx[n-(i-1)+1][m-(p-i+1)+1]+map[n-i+1][m-(p-i)+1];
	memset(val,0,sizeof(val));
	for(int i=n;i>=n-K+1;--i)
		for(int j=m;j>=m-K+1;--j) if(K-abs(n-K+1-i)-abs(m-K+1-j)>0)
		{
			val[n-K+1][m-K+1][0]+=map[i][j]*(K-abs(n-K+1-i)-abs(m-K+1-j));
			val[n-K+1][m-K+1][1]+=map[i][j];
		}
	ans[n-K][m-K]+=val[n-K+1][m-K+1][0];
	for(int i=n-K+1;i>=K;--i)
		for(int j=m-K+1;j>=K;--j)
		{
			if(i==n-K+1 && j==m-K+1) continue;
			if(j==m-K+1)
			{
				val[i][j][0]=val[i+1][j][0]-val[i+1][j][1]+(sumh[i][j][1]-sumh[i][j+K][1])+(K-(m-j+1))*(sumh[i][j][0]-sumh[i][j+K][0]);
				val[i][j][1]=val[i+1][j][1]-(sumx[i+1][j+K-1]-sumx[i+1+K-1][j])-map[i+1+K-1][j]+(sumh[i][j][0]-sumh[i][j+K][0]);
			}
			else
			{
				val[i][j][0]=val[i][j+1][0]-val[i][j+1][1]+(suml[i][j][1]-suml[i+K][j][1])+(K-(n-i+1))*(suml[i][j][0]-suml[i+K][j][0]);
				val[i][j][1]=val[i][j+1][1]-(sumx[i][j+1+K-1]-sumx[i+K-1][j+1])-map[i+K-1][j+1]+(suml[i][j][0]-suml[i+K][j][0]);
			}
			ans[i-1][j-1]+=val[i][j][0];
		}
	/*cout<<"cao--------------------\n";
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<val[i][j][0]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cout<<val[i][j][1]<<" ";
		}
		cout<<endl;
	}
	cout<<"cao--------------------\n";*/
	//----------------------------End wo tu le
	K+=2;
	out();
	return 0;
}
//ore no turn,draw!