#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
#define sc second
#define fr first
int n,del,X[300005],m,A[300005],B[300005],C[300005],b[300005],c[300005];
pair<int,int>a[300005];
inline void put(re x,re y,re k)
{
	if(X[a[x].sc]>X[a[y].sc]) swap(x,y);
	m++;A[m]=a[x].sc,B[m]=a[y].sc,C[m]=k;
}
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=n;i++) scanf("%d",&a[i].fr),a[i].sc=i,X[i]=a[i].fr;
	for(re i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(re i=1;i<=n;i++) del+=(c[i]=b[i]-a[i].fr);
	if(del!=0) return puts("NO"),0;
	re j=1;
	for(re i=1;i<=n;i++) 
	{
		if(c[i]<0) return puts("NO"),0;
		while(c[i])
		{
			while(j<=n&&c[j]>=0) j++;
			re x=min(c[i],-c[j]);
			c[i]-=x;c[j]+=x;
			A[++m]=a[i].sc,B[m]=a[j].sc,C[m]=x;
		}
	}
	puts("YES");
	cout<<m<<endl;
	for(re i=1;i<=m;i++)
	printf("%d %d %d\n",A[i],B[i],C[i]);
}