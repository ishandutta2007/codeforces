#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n,k;
int ask(int x)
{
	cout<<"? "<<x<<endl;
	int a;
	cin>>a;
	return a;
}
int main()
{
	scanf("%d %d",&n,&k);
	int x;
	while(1)
	{
		x=rnd()%n+1;
		int w=ask(x);
		if(w<k)
		{
			int len=1;
			while(ask((x+len-1)%n+1)<k)
				len<<=1;
			len>>=1;
			while(len)
			{
				if(ask((x+len-1)%n+1)<k)
					x=(x+len-1)%n+1;
				len>>=1;
			}
			cout<<"! "<<x%n+1<<endl;
			break;
		}
		if(w>k)
		{
			int len=1;
			while(ask((x+n-len-1)%n+1)>k)
				len<<=1;
			len>>=1;
			while(len)
			{
				if(ask((x+n-len-1)%n+1)>k)
					x=(x+n-len-1)%n+1;
				len>>=1;
			}
			cout<<"! "<<(x+n-2)%n+1<<endl;
			break;
		}
	}
}