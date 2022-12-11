#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long hash1[11][100010],hash2[11][100010],pow1[100010],pow2[100010],ans;
int n,a[11][100010],m,po[11][100010],l,r,mid,s;
inline bool check(int w,int len)
{
	for(int i=1;i<=m;++i)
		if(len+po[i][w]>n+1)return 0;
	bool flag=0;
	int p1,p=po[1][w];
	long long s11=hash1[1][po[1][w]+len-1]-hash1[1][po[1][w]-1]*pow1[len],s12=hash2[1][po[1][w]+len-1]-hash2[1][po[1][w]-1]*pow2[len];
	long long s21,s22;
	for(int i=2;i<=m;++i)
	{
		p1=po[i][w];
		s21=hash1[i][po[i][w]+len-1]-hash1[i][po[i][w]-1]*pow1[len],s22=hash2[i][po[i][w]+len-1]-hash2[i][po[i][w]-1]*pow2[len];
		if(s11!=s21||s12!=s22)
		{
			flag=1;
			break;	
		}
	}
	if(flag)return 0;
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	pow1[0]=pow2[0]=1;
	for(int i=1;i<=n;++i)
		pow1[i]=pow1[i-1]*100007,pow2[i]=pow2[i-1]*100009;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
			hash1[i][j]=hash1[i][j-1]*100007+a[i][j];
			hash2[i][j]=hash2[i][j-1]*100009+a[i][j];
			po[i][a[i][j]]=j;
		}
	for(int i=1;i<=n;++i)
	{
		l=1;
		r=n;
		while(l<r)
		{
			mid=l+r>>1;
			if(check(i,mid))l=mid+1;
			else r=mid-1;
		}
		if(check(i,mid+2))s=mid+2;
		else if(check(i,mid+1))s=mid+1;
		else if(check(i,mid))s=mid;
		else if(check(i,mid-1))s=mid-1;
		else s=mid-2;
		ans+=s;
	}
	printf("%I64d",ans);
	return 0;
}