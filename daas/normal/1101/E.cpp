#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<set>
#define ll long long
using namespace std;
inline int read()
{
    int kkk=0,x=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-')
        c=getchar(),x=-1;
    while(c>='0' && c<='9')
        kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
    return kkk*x;
}
int n,mx,my;
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		if(s[0]=='+')
		{
			int x=read(),y=read();
			if(x<y)
				swap(x,y);
			mx=max(mx,x);
			my=max(my,y);
		}
		else
		{
			int a=read(),b=read();
			if(a<b)
				swap(a,b);
			if(mx<=a && my<=b)
				puts("YES");
			else
				puts("NO");
		}
	}
    return 0;
}