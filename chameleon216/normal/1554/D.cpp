#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

#define pc putchar
void Divide(int l,int r,char c)
{
	int len=r-l+1,a=c++,b=c++;
	if(len<=6)
	{
		c-=2;
		Fr(i,l,r)pc(c++);
	}
	else if(len<=10)
	{
		pc(a),pc(b),pc(b);
		Fr(i,l+3,r-3)pc(c++);
		pc(b),pc(a),pc(a);
	}
	else if(len<=13)
	{
		pc(a),pc(b),pc(b),pc(a),pc(b);
		Fr(i,l+5,r-5)pc(c++);
		pc(b),pc(a),pc(a),pc(b),pc(a);
	}
	else if(len%3==2)
	{
		int n=(len-2)/3;
		Divide(l,l+n-1,c);
		pc(a);
		Divide(l+n+1,r-n-1,c);
		pc(b);
		Divide(r-n+1,r,c);
	}
	else if(len%3==0)
	{
		int n=(len-6)/3;
		Divide(l,l+n-1,c);
		pc(a),pc(b),pc(b);
		Divide(l+n+3,r-n-3,c);
		pc(b),pc(a),pc(a);
		Divide(r-n+1,r,c);
	}
	else
	{
		int n=(len-10)/3;
		Divide(l,l+n-1,c);
		pc(a),pc(b),pc(b),pc(a),pc(b);
		Divide(l+n+5,r-n-5,c);
		pc(b),pc(a),pc(a),pc(b),pc(a);
		Divide(r-n+1,r,c);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int x;
		scanf("%d",&x);
		Divide(1,x,'a'),pc('\n');
	}
	return 0;
}