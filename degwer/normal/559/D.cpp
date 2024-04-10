#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<double,double>pdd;
typedef long long ll;
typedef pair<ll,ll>pii;
double p2[120001];
double eps=1e-12;
ll gcd(ll a,ll b)
{
	a=abs(a);
	b=abs(b);
	for(;;)
	{
		if(a==0)return b;
		if(b==0)return a;
		if(a>b)swap(a,b);
		b%=a;
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	for(int i=0;i<num;i++)
	{
		ll za,zb;
		scanf("%I64d%I64d",&za,&zb);
		vec.push_back(make_pair(za,zb));
	}
	p2[0]=1;
	for(int i=1;i<=100;i++)
	{
		p2[i]=p2[i-1]/2.0;
		if(p2[i]<eps)p2[i]=0;
	}
	double sumb=0;
	double sums=0;
	for(int i=0;i<num;i++)
	{
		for(int j=1;j<min(50,num);j++)
		{
			sumb+=(double(gcd((vec[i].first-vec[(i+j)%num].first),(vec[i].second-vec[(i+j)%num].second))-1))*p2[j+1];
			sums+=(double(vec[i].first*vec[(i+j)%num].second)-double(vec[i].second*vec[(i+j)%num].first))*(p2[j+1]/2.0);
			if(num<=50)sumb-=(double(gcd((vec[i].first-vec[(i+j)%num].first),(vec[i].second-vec[(i+j)%num].second))-1))*p2[num];
		}
	}
	double sump=double(num)/2.0;
	sump-=double(num*(num-1)/2.0)*2.0*p2[num];
	sump-=double(num)*p2[num];
	double tim=1.0;
	if(p2[num]>eps)tim=(1.0/p2[num])/(1.0/p2[num]-double(num*(num-1)/2.0)-num-1);
	sums*=tim;
	sumb*=tim;
	sump*=tim;
	printf("%.10lf\n",sums+1.0-(sumb+sump)/2.0);
}