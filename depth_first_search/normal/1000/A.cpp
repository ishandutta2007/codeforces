#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
using namespace std;
int n,a[10];
int read()
{
	int x=0,f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') (x*=10)+=ch-'0',ch=getchar();
	return x*=f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		if(s=="M") a[1]++;
		else if(s=="L") a[2]++;
		else if(s=="XL") a[3]++;
		else if(s=="XXL") a[4]++;
		else if(s=="XXXL") a[5]++;
		else if(s=="S") a[6]++;
		else if(s=="XS") a[7]++;
		else if(s=="XXS") a[8]++;
		else if(s=="XXXS") a[9]++;
	}
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		if(s=="M") a[1]--;
		else if(s=="L") a[2]--;
		else if(s=="XL") a[3]--;
		else if(s=="XXL") a[4]--;
		else if(s=="XXXL") a[5]--;
		else if(s=="S") a[6]--;
		else if(s=="XS") a[7]--;
		else if(s=="XXS") a[8]--;
		else if(s=="XXXS") a[9]--;
	}
	int tot=0;
	for(int i=1;i<=9;i++) tot+=abs(a[i]);
	return write(tot>>1),0;
}