#include<bits/stdc++.h>
#define li long long
const long long MOD=998244353;
using namespace std;
long long test,p,q,l,r;
string str;
long long hsh[1919810],hsh2[1919810],pw[1919810];
inline long long read()
{
    register long long num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline long long getHash2(long long l,long long r)
{
	return (hsh2[l]+MOD-(li)hsh2[r+1]*pw[r-l+1]%MOD)%MOD;
}
inline long long getHash(long long l,long long r)
{
	return (hsh[r]+MOD-(li)(l==0?0:hsh[l-1])*pw[r-l+1]%MOD)%MOD;
}
inline bool check(long long l,long long r)
{
	return getHash(l,r)==getHash2(l,r);
}
inline void solve()
{
	cin>>str,p=0,q=str.length()-1,l=0;
	hsh[0]=str[0]-'a'+1,hsh2[q]=str[q]-'a'+1,hsh2[q+1]=0;
	while(str[p]==str[q]&&q>=0) p++,q--;
	if(q==-1)
	{
		cout<<str<<endl;
		return;
	}
	for(register int i=1;i<str.length();i++) hsh[i]=((li)hsh[i-1]*19491001+(str[i]-'a'+1))%MOD;
	for(register int i=str.length()-2;i>=0;i--) hsh2[i]=((li)hsh2[i+1]*19491001+(str[i]-'a'+1))%MOD;
	for(register int i=q;i>=p;i--)
	{
		if(check(p,i))
		{
			l=p,r=i;
			break;
		}
	}
	for(register int i=p;i<=q;i++)
	{
		if(check(i,q))
		{
			if(q-i>=r-l)
			{
				l=i,r=q;
			}
			break;
		}
	}
	for(register int i=0;i<p;i++)
	{
		putchar(str[i]);
	}
	for(register int i=l;i<=r;i++)
	{
		putchar(str[i]);
	}
	for(register int i=q+1;i<str.length();i++)
	{
		putchar(str[i]);
	}
	puts("");
}
int main()
{
	test=read(),pw[0]=1;
	for(register int i=1;i<1000001;i++) pw[i]=(li)pw[i-1]*19491001%MOD;
	for(register int i=0;i<test;i++) solve();
return 0;
}