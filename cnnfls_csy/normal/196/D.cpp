#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);i<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);i>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
string st;
int n,m,i,j,k,fi,lst,c;
unsigned long long e=1e9+7,h1[400005],h2[400005],po[400005];
bool bo=0;
bool check(int l,int r)
{
	if (l<1) return 0;
	return (h1[r]-h1[l-1]*po[r-l+1])*po[l-1]==h2[r]-h2[l-1];
}
void add(int x)
{
	if (st[x]=='z')
	{
		if (x==1)
		{
			puts("Impossible");
			exit(0);
		}
		st[x]='a';
		add(x-1);
	}
	else
	{
		st[x]++;
		lst=x;
	}
	h1[x]=h1[x-1]*e+st[x];
	h2[x]=h2[x-1]+st[x]*po[x-1];
}
int main()
{
	cin>>n>>st;
	st=" "+st;
	po[0]=1;
	for (i=1;i<st.length();i++)
	{
		po[i]=po[i-1]*e;
		h1[i]=h1[i-1]*e+st[i];
		h2[i]=h2[i-1]+st[i]*po[i-1];
	}
	add(st.length()-1);
	lst=fi=st.length()-1;
	for (i=n-1;i<st.length();i++)
	{
		if (check(i-n+1,i)||check(i-n,i))
		{
			fi=i;
			break;
		}
	}
	i=fi;
	while (i<st.length())
	{
	//	cerr<<st<<endl;
		if (i>lst) st[i]='a';
		h1[i]=h1[i-1]*e+st[i];
		h2[i]=h2[i-1]+st[i]*po[i-1];
		while (check(i-n+1,i)||check(i-n,i))
		{
			add(i);
			i=lst-1;
		}
		i++;
	}
	cout<<st.substr(1);
	return 0;
}