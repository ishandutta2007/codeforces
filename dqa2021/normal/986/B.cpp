#include<cstdio>
typedef long long ll;
char ch;
void read(int &x)
{
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for (x=0;ch<='9'&&ch>='0';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
}
int n,w;
ll ans;
int tri[1000010];
void add(int x)
{for (;x<=n;x+=x&-x) tri[x]++;}
int calc(int x)
{
	int res=0;
	for (;x;x-=x&-x) res+=tri[x];
	return res;
}
int main()
{
	read(n);
	for (int i=1;i<=n;i++)
	{
		read(w);
		add(w);
		ans+=i-calc(w);
	}
	puts(ans%2==n%2?"Petr":"Um_nik");
	return 0;
}