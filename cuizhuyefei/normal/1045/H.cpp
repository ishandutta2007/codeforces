#include<cstdio>
#include<cstring>

const int mod=1000000007;
int a[100001],b[100001],c00,c01,c10,c11,n,la,an,bn,ans,C00,C01,C10,C11,aN,bN,jc[110001],inv[110001];
char s[100001];

int add(int x,int y) {return (x+y>=mod)?(x+y-mod):(x+y);}
int C(int x,int y) 
{
	if (x<y) return 0;
	return 1ll*jc[x]*inv[y]%mod*inv[x-y]%mod;
}

int query(int l,int r,int x)
{
	if (l<0) l=0;
	if (l>r) return 0;
	return (C(r+1,x+1)-C(l,x+1)+mod)%mod;
}

int calc()
{
	if (aN==0) return 0;
	if (c00+c11>aN) return 0;
	if (c10==0) 
	{
		if (c11<aN) return 1;
		return (an==1?1:0);
	}
	if (c00+c11<aN) return 1ll*C(c00-1,c10-1)*C(c11-1,c01-1)%mod;
	int ans=0;
	for (int i=1; i<=an; i++)
		if (i&1)
		{
			if (c01==1) 
			{
				if (c11>a[i]) return ans;
				return add(ans,1);
			}
			ans=add(ans,1ll*query(c11-a[i],c11-2,c01-2)*C(c00-1,c10-1)%mod);
			c11-=a[i]; c01--;
			if (c11<c01) return ans;
		} else
		{
			if (c10==1)
			{
				if (c00<a[i]) return ans;
				return add(ans,1);
			}
			ans=add(ans,1ll*query(0,c00-a[i]-2,c10-2)*C(c11-1,c01-1)%mod);
			c00-=a[i]; c10--;
			if (c00<c10) return ans;
		}
}

int quickmi(int a,int b)
{
	int t=1;
	while (b)
	{
		if (b&1) t=1ll*t*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return t;
}

int main()
{
	jc[0]=1;
	for (int i=1; i<=110000; i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[110000]=quickmi(jc[110000],mod-2);
	for (int i=110000; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%s",s);
	n=strlen(s); 
	for (int i=n-1; i>=0; i--)
		if (s[i]=='1') {la=i; break;}
	if (la==0) 
	{
		n--;
		for (int i=0; i<n; i++) s[i]='1';
	} else
	{
		s[la]='0';
		for (int i=la+1; i<n; i++) s[i]='1';
	}
	la=0; an=0; aN=n;
	for (int i=1; i<n; i++)
		if (s[i]!=s[i-1]) a[++an]=i-la,la=i;
	a[++an]=n-la;
	scanf("%s",s);
	n=strlen(s); la=0; bn=0; bN=n;
	for (int i=1; i<n; i++)
		if (s[i]!=s[i-1]) b[++bn]=i-la,la=i;
	b[++bn]=n-la;
	scanf("%d%d%d%d",&c00,&c01,&c10,&c11);
	c11+=c01+1; c00+=c10; c01++;
	C00=c00; C11=c11; C01=c01; C10=c10;
	if (c10!=c01&&c10!=c01-1||c11<c01||c00<c10) {printf("0\n"); return 0;}
	ans=calc(); an=bn; aN=bN;
	for (int i=1; i<=bn; i++) a[i]=b[i];
	c00=C00; c01=C01; c11=C11; c10=C10;
	ans=(calc()-ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}