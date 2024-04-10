#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
using namespace std;
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
	int T=read();
	while(T--)
	{
		string s;
		read_string(s);
		if(s.length()>10) putchar(s[0]),write(s.length()-2),putchar(s[s.length()-1]),putchar('\n');
		else cout<<s<<endl;
	}
	return 0;
}