#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int n,A,cf,cm,k,bk;
LL m,best;
int a[100005],id[100005];
LL s[100005];

bool cmpa(const int &e1,const int &e2)
{return a[e1]>a[e2];}

int main()
{
	scanf("%d%d%d%d%I64d",&n,&A,&cf,&cm,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),id[i]=i;
	sort(id+1,id+n+1,cmpa);
	for(int i=n;i;i--)
		s[i]=a[id[i]]+s[i+1];
	if((LL)n*A-s[1]<=m)
	{
		cout<<(LL)n*cf+(LL)A*cm<<endl;
		for(int i=1;i<=n;i++)printf("%d%c",A," \n"[i==n]);
		return 0;
	}
	a[0]=A;best=-1;
	int p=n+1;
	LL tt=m;
	for(k=0;k<n;k++)
	{
		m-=A-a[id[k]];
		if(m<0)break;
		p=max(k+1,p);
		for(;p>k+1&&(LL)a[id[p-1]]*(n-p+1)-s[p]<=m;p--);
		for(;p<n&&(LL)a[id[p]]*(n-p+1)-s[p]>m;p++);
		int tm=min(a[id[p]]+(m-((LL)a[id[p]]*(n-p+1)-s[p]))/(n-p+1),(LL)A);
		if((LL)cf*k+(LL)cm*tm>best)
			best=(LL)cf*k+(LL)cm*tm,bk=k;
	}
	m=tt;
	cout<<best<<endl;
	k=bk;
	for(int i=1;i<=k;i++)
		m-=A-a[id[i]];
	for(p=n+1;p>k+1&&(LL)a[id[p-1]]*(n-p+1)-s[p]<=m;p--);
	int tm=min(a[id[p]]+(m-((LL)a[id[p]]*(n-p+1)-s[p]))/(n-p+1),(LL)A);
	for(int i=1;i<=k;i++)
		a[id[i]]=A;
	for(int i=1;i<=n;i++)
		a[i]=max(a[i],tm);
	for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}