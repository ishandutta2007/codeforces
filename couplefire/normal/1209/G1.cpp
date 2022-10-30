#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int i,n,q,p,l,r,m,a[N],x[N],c[N];
int main()
{
    scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]),c[x[a[i]]=i,a[i]]++;
	for(i=1;i<=n;i++)
    {
		l=i,r=x[a[i]],m=c[a[i]];
		while(i<r)
        {
            i++;
            r=max(r,x[a[i]]);
            m=max(m,c[a[i]]);
        }
		p+=r-l+1-m;
	}
	printf("%d\n",p);
    return 0;
}