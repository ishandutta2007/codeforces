#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int n,a[300005],b[300005],na,nb,m,maxn=-1;
inline bool cmp1(re x,re y) {return b[x]>b[y];}
inline bool cmp2(re x,re y) {return a[x]>a[y];}
struct node{
	int l,r,id;
	node() {}
	node(re x,re y,re z) : l(x),r(y),id(z) {}
	bool operator <(node x) const {return l<x.l;}
}t[300005];
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	for(re i=1;i<=n;i++) (a[i]>=b[i])?nb++:na++;
	if(na<nb) for(re i=1;i<=n;i++) 
	a[i]=n*2-a[i]+1,b[i]=n*2-b[i]+1;
	for(re i=1;i<=n;i++)
	if(a[i]<b[i])
	{
		t[++m]=node(a[i],b[i],i);
		if(maxn==-1) maxn=m;
		else if(t[m].r>t[maxn].r) maxn=m;
	}
	cout<<m<<endl<<t[maxn].id<<" ";
	for(re i=maxn;i<m;i++) t[i]=t[i+1];
	sort(t+1,t+m);
	for(re i=m-1;i;i--) printf("%d ",t[i].id);
}