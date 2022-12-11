#include<cstdio>
#include<cstring>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#define ll long long
#define MAX 100000
int w[MAX+5];
ll f[2][2];
char s[2][MAX+5];
bool asb(char*a,char*b,int oa,int ob)
{
	int i,j,as=0,bs=0,ae=strlen(a),be=strlen(b);
	if(oa<0){as=ae-1;ae=-1;}
	if(ob<0){bs=be-1;be=-1;}
	for(i=as,j=bs;i!=ae&&j!=be;i+=oa,j+=ob)
	{
		if(a[i]<b[j])return true;
		if(a[i]>b[j])return false;
	}
	return i==ae;
}
void renew(ll&a,ll b){if(a<0||(b>=0&&b<a))a=b;}
int main()
{
	int n,i,nw,ls;ll ans=-1;
	read(n);
	for(i=0;i<n;i++)read(w[i]);
	scanf("%s",&s[0]);f[0][1]=w[0];
	for(i=1;i<n;i++)
	{
		nw=i&1;ls=nw^1;
		f[nw][0]=-1;f[nw][1]=-1;
		scanf("%s",&s[nw]);
		if(f[ls][0]>=0)
		{
			if(asb(s[ls],s[nw],1,1))renew(f[nw][0],f[ls][0]);
			if(asb(s[ls],s[nw],1,-1))renew(f[nw][1],f[ls][0]+w[i]);
		}
		if(f[ls][1]>=0)
		{
			if(asb(s[ls],s[nw],-1,1))renew(f[nw][0],f[ls][1]);
			if(asb(s[ls],s[nw],-1,-1))renew(f[nw][1],f[ls][1]+w[i]);
		}
	}
	renew(ans,f[nw][0]);renew(ans,f[nw][1]);
	printf("%I64d",ans);
}