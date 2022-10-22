#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
using namespace std;
int n;
string s;
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
void read_string(string &s)
{
	s="";char ch=getchar();
	while(ch==' '||ch=='\n') ch=getchar();
	while(ch!=' '&&ch!='\n') s+=ch,ch=getchar();
}
int main()
{
	n=read(),read_string(s);
	for(int i=2;i<=n;i++) if(n%i==0) for(int j=0;j<i/2;j++) swap(s[j],s[i-j-1]);
	cout<<s;
	return 0;
}