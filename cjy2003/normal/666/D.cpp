#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
long long x[5],y[5],ans,nx[5],ny[5],ax[5],ay[5];
bool used[5];
int p[5];
#define a p[1]
#define b p[2]
#define c p[3]
#define d p[4]
void getans()
{
	long long mx=0;
	for(int i=1;i<=4;++i)
	{
		if(x[i]!=nx[i]&&y[i]!=ny[i])return;
		if(x[i]==nx[i])mx=max(mx,abs(y[i]-ny[i]));
		if(y[i]==ny[i])mx=max(mx,abs(x[i]-nx[i]));
	}
	if(mx<ans)
	{
		ans=mx;
		for(int i=1;i<=4;++i)ax[i]=nx[i],ay[i]=ny[i];
	}
}
void check11()
{
	if(x[d]>=nx[b])return;
	nx[d]=x[d],ny[d]=ny[b]+nx[b]-nx[d];
	nx[c]=nx[b],ny[c]=ny[d];
	nx[a]=nx[d],ny[a]=ny[b];
//	if(a==3&&b==4&&c==1&&d==2)printf("!");
	getans();
}
void check12()
{
	if(y[d]<=ny[b])return;
	ny[d]=y[d],nx[d]=nx[b]-ny[d]+ny[b];
	nx[c]=nx[b],ny[c]=ny[d];
	nx[a]=nx[d],ny[a]=ny[b];
	getans();	
}
void check1()
{
	nx[b]=x[b],ny[b]=y[a];
	check11();check12();
}
void check21()
{
	if(x[c]<=nx[a])return;
	nx[c]=x[c],ny[c]=ny[a]+nx[c]-nx[a];
	nx[b]=nx[c],ny[b]=ny[a];
	nx[d]=nx[a],ny[d]=ny[c];
	getans();
}
void check22()
{
	if(y[c]<=ny[a])return;
	ny[c]=y[c],nx[c]=nx[a]+ny[c]-ny[a];
	nx[b]=nx[c],ny[b]=ny[a];
	nx[d]=nx[a],ny[d]=ny[c];
	getans();	
}
void check2()
{
	nx[a]=x[a],ny[a]=y[b];
	check21();check22();
}
void check3()
{
	if(x[a]>=x[b])return;
	if(x[d]!=x[a])
	{
		nx[d]=x[a],ny[d]=y[d];
		nx[c]=x[b],ny[c]=y[d];
		nx[a]=x[a],ny[a]=ny[d]-(x[b]-x[a]);
		nx[b]=x[b],ny[b]=ny[a];
		getans();
	}
	else if(x[c]!=x[b])
	{
		nx[c]=x[b],ny[c]=y[c];
		nx[d]=x[a],ny[d]=y[c];
		nx[a]=x[a],ny[a]=ny[d]-(x[b]-x[a]);
		nx[b]=x[b],ny[b]=ny[a];
		getans();
	}
	else
	{
		if(ny[a]>=ny[d]||ny[b]>=ny[d])return;
		nx[a]=x[a],nx[b]=x[b],nx[c]=x[c],nx[d]=x[d];
		long long l=x[b]-x[a],mi=min(min(y[a],y[b]),min(y[c]-l,y[d]-l)),mx=max(max(y[a],y[b]),max(y[c]-l,y[d]-l));
		long long pos=mi+mx>>1;
		ny[a]=ny[b]=pos;ny[c]=ny[d]=pos+l;
		getans();
	}
}
void check4()
{
	if(x[a]>=x[b]||y[a]!=y[b])return;
	long long l;
	nx[d]=x[d],ny[d]=y[c];
	nx[b]=nx[d],ny[b]=y[b];
	l=ny[d]-ny[b];
	if(l>0)
	{
		nx[a]=nx[b]-l,ny[a]=y[a];
		nx[c]=nx[a],ny[c]=ny[d];
		getans();		
	}

	nx[c]=x[c],ny[c]=y[d];
	nx[a]=nx[c],ny[a]=y[a];
	l=ny[c]-ny[a];
	if(l>0)
	{
		nx[b]=nx[a]+l,ny[b]=y[b];
		nx[d]=nx[b],ny[d]=ny[c];
		getans();
	}
	
	l=x[d]-x[c];
	if(l>0)
	{
		nx[a]=nx[c]=x[c];
		nx[b]=nx[d]=x[d];
		ny[a]=ny[b]=y[a];
		ny[c]=ny[d]=y[a]+l;
		getans();
	}
	
	if(y[c]==y[d]&&y[c]>y[a])
	{
	//	if(a==3&&b==2&&c==1&&d==4)printf("!!!\n");
		long long l=y[c]-y[a],mi=min(min(x[a],x[b]-l),min(x[c]-l,x[d])),mx=max(max(x[a],x[b]-l),max(x[c]-l,x[d]));
		long long pos=mi+mx>>1;
	//	if(a==3&&b==2&&c==1&&d==4)printf("%lld %lld %lld %lld\n",l,mi,mx,pos);
		ny[a]=ny[b]=y[a];
		ny[c]=ny[d]=y[c];
		nx[a]=nx[d]=pos;
		nx[b]=nx[c]=pos+l;
		getans();
	}
}
void check()
{
//	if(a==3&&b==4&&c==1&&d==2)printf("!!!\n");
	check1();
	check2();
	check3();
	check4();
}
void dfs(int w)
{
	if(w==5)return check();
	for(int i=1;i<=4;++i)if(!used[i])used[i]=1,p[w]=i,dfs(w+1),used[i]=0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=4;++i)scanf("%lld %lld",&x[i],&y[i]);
		ans=0x3f3f3f3f3f3f3f3f;
		dfs(1);
		if(ans==0x3f3f3f3f3f3f3f3f)printf("-1\n");
		else
		{
			printf("%lld\n",ans);
			for(int i=1;i<=4;++i)printf("%lld %lld\n",ax[i],ay[i]);
		}
	}
	return 0;
}