#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
int n;
unsigned A,B,C,D,ans;
int calc(int x)
{
	if (x%6!=1&&x%6!=5)return 0;
	return x/3;
}
bitset<100010005>pr;
void prime()
{
	pr[0]=true;
	for (int i=3;i<3e8;i+=2)
	{
		if (i%6!=1  && i%6!=5) continue;
		if (pr[i/6*2+(i%6==5)]==false && i*i<3e8)
			for (int j=i+i;j<3e8;j+=i)
				if (j%6==1 || j%6==5)
					pr[j/6*2+(j%6==5)]=true;
	}
} 
inline bool check(int x)
{
	if (x==2 || x==3) return true;
	if (x%6!=1 && x%6!=5) return false;
	return !pr[x/6*2+(x%6==5)];
}
void Calc(int x)
{
	unsigned s=A*x*x*x+B*x*x+C*x+D;
	for(int i=n/x;i;i/=x) ans+=s*i;
}
int main()
{
	prime();
	scanf("%d%u%u%u%u",&n,&A,&B,&C,&D);
	if (n>=2) Calc(2);
	for (int i=3;i<=n;i+=2)
		if (check(i)) Calc(i);
	printf("%u\n",ans);
	return 0;
}