#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}
//typedef long long ll;

int n,m,w[300010],ww[300010];
bool chk(int x)
{
	memcpy(ww,w,sizeof ww);
	for (int i=1;i<=n;i++)
	{
		if (ww[i]<=ww[i-1]&&ww[i]+x>=ww[i-1]) ww[i]=ww[i-1];
		else if (ww[i]>ww[i-1]&&ww[i]+x>=ww[i-1]+m) ww[i]=ww[i-1];
		if (ww[i]<ww[i-1]) return false;
	}
	return true;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) w[i]=read();
//	printf("%d\n",chk(0));
	int l=0,r=m-1,mid;
	while (l<r)
	{
		mid=l+r>>1;
		if (chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}