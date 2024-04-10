#include <iostream>
using namespace std;
bool z[1002];
char s;
int read()
{
	int x=0;
	while(true)
	{
		s=getchar();
		if(s=='\n'||s==',')
		return x;
		int d=s-'0';
		x=x*10+d;
	}
} 
int main()
{
	int mx=0;
	for(int i=0;s!='\n';)
	{
		i=read();
		z[i]=1;
		mx=max(mx,i);
	}
	for(int i=1;i<=mx;i++)
	{
		if(z[i]&&!z[i-1]&&!z[i+1])
		{
			cout<<i;
			if(i!=mx)
			cout<<',';
		}
		if(z[i]&&z[i-1]&&!z[i+1])
		{
			cout<<'-'<<i;
			if(i!=mx)
			cout<<',';	
		}
		if(z[i]&&!z[i-1]&&z[i+1])
		cout<<i;
	}
	return 0;
}