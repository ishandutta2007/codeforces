#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],i,ans[N],T;
int d,t,phi,s;
struct str{
	int a,x;
};
map<int,int> m;
map<int,vector<str> > w;
long long qpow(long long a,long long b,long long M)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
bool cmp(str a,str b)
{
	return a.a<b.a;
}
void cal(vector<str> a)
{
	long long ni=qpow(d,phi-1,t);
	//cout<<d<<' '<<phi<<' '<<ni<<endl;
	for(int i=0;i<a.size();++i)
	{
		a[i].a=a[i].a*ni%t;
		//cout<<a[i].a<<' ';
	}
	//cout<<endl;
	sort(a.begin(),a.end(),cmp);
	if(a.size()==1)
		ans[a[0].x]=t;
	else
		for(int i=0;i<a.size();++i)
			ans[a[i].x]=((a[(i+1)%a.size()].a-a[i].a)%t+t)%t;
}
int main()
{
	scanf("%d %d",&T,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s=(s+a[i])%T;
	}
	int g=__gcd(s,T);
	d=s/g,t=T/g;
	s=0;
	for(i=1;i<=n;++i)
	{
		if(!m[s])
		{
			w[s%g].push_back((str){s/g,i});
			m[s]=1;
		}
		s=(s+a[i+1])%T;
	}
	int tmp=t;
	phi=t;
	for(i=2;i*i<=tmp;++i)
		if(tmp%i==0)
		{
			phi=phi/i*(i-1);
			while(tmp%i==0)
				tmp/=i;
		}
	if(tmp!=1)
		phi=phi/tmp*(tmp-1);
	for(auto it:w)
		cal(it.second);
	for(i=1;i<=n;++i)
		printf("%d ",ans[i]);
}