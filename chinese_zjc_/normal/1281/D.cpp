//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
#define s(a,b) s[a*c-c+b]
using namespace std;
int n,r,c,P;
char s[3000001];
bool h[3000001],z[3000001],flag;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	while(n)
	{
		--n;
		P=0;
		cin>>r>>c;
		fill(h+1,h+1+r,true);
		fill(z+1,z+1+c,true);
		for(int i=1;i<=r;++i)
		{
			for(int j=1;j<=c;++j)
			{
				cin>>s(i,j);
				if(s(i,j)=='P')
				{
					++P;
					h[i]=false;
					z[j]=false;
				}
			}
		}
		if(P==r*c)
		{
			cout<<"MORTAL"<<endl;
			continue;
		}
		if(P==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(h[1]||h[r]||z[1]||z[c])
		{
			cout<<1<<endl;
			continue;
		}
		flag=false;
		for(int i=2;i<r;++i)
		{
			if(h[i])
			{
				cout<<2<<endl;
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		flag=false;
		for(int i=2;i<c;++i)
		{
			if(z[i])
			{
				cout<<2<<endl;
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		if(s(1,1)=='A'||s(1,c)=='A'||s(r,1)=='A'||s(r,c)=='A')
		{
			cout<<2<<endl;
			continue;
		}
		flag=false;
		for(int i=2;i<r;++i)
		{
			if(s(i,1)=='A'||s(i,c)=='A')
			{
				cout<<3<<endl;
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		flag=false;
		for(int i=2;i<c;++i)
		{
			if(s(1,i)=='A'||s(r,i)=='A')
			{
				cout<<3<<endl;
				flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		cout<<4<<endl;
	}
	return 0;
}