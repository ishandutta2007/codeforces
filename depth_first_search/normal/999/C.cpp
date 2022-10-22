#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
using namespace std;
int n,m,a[30],b[30];
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
	while(ch!=' '&&ch!='\n') s+=ch,a[ch-'a']++,ch=getchar();
}
int main()
{
	n=read(),m=read(),read_string(s);
	for(int i=0;i<26;i++) if(a[i]>=m) {b[i]=m;break;}else m-=(b[i]=a[i]);
	for(int i=0;i<s.length();i++) if(!b[s[i]-'a']) putchar(s[i]);else b[s[i]-'a']--;
	return 0;
}