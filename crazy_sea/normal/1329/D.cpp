#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t[26],sum,mx,w,s2;
const int N=2e5+10;
void update()
{
	sum=mx=0;
	for(int i=0;i<26;i++)
		sum+=t[i],mx=max(mx,t[i]);
	s2=sum/2+(sum&1);
}
void del(int c)
{
	t[c-'a']--;
	update();
}
char a[N],s[N],t2[N];
int len,l2;
void pop()
{
	int x=len;
	while(len>1&&a[len]!=a[len-1]) len--;
	printf("%d %d\n",len--,x);
	if(len) del(a[len]);
	l2--;
}
void push1(char c)
{
	if(a[len]==c)
	{
		if(l2&&t2[l2]!=c) pop(),del(c);
		else t2[++l2]=c;
	}
	a[++len]=c;
}
void push2(char c)
{
	if(a[len]==c)
	{
		if(l2&&((c==w)^(t2[l2]==w))) pop();
		else t2[++l2]=c;
	}
	a[++len]=c;
}
int n,T,j;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s);
		for(int i=1;i<n;i++)
			if(s[i]==s[i-1]) t[s[i]-'a']++;
		update(),j=0;
		if(mx<s2) printf("%d\n",s2+1);
		else printf("%d\n",mx+1);
		while(mx<sum/2+(sum&1)) push1(s[j++]);
		for(int i=1;i<26;i++) if(t[w]<t[i]) w=i;
		w+='a';
		while(j<n) push2(s[j++]);
		while(len) pop();
		for(int i=0;i<26;i++) t[i]=0;
		len=l2=w=0;
	}
}