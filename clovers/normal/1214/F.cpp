#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=610001;
const int inf=(int)5e16;

struct node{
	int val,id;
};
node a[N],b[N];

bool cmp(node x,node y)
{
	if(x.val==y.val) return x.id<y.id;
	return x.val<y.val;
}

int n,m,ans[N],pos[N];

signed main() 
{
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].val);
		a[i].id=i;
	}
	for(int i=n+1;i<=n+n;i++)
	{
		scanf("%lld",&b[i].val); b[i].id=i-n;
		b[i+n].val=b[i].val+m; b[i+n].id=i-n;
		b[i-n].val=b[i].val-m; b[i-n].id=i-n;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+3*n+1,cmp);
	for(int i=1,j=1;i<=n;i++)
	{
		while(a[i].val>=b[j].val&&j<=3*n) j++;
		//1~j-1 a[i]>=b[j]
		ans[0]+=a[i].val;
		ans[j-i+1]-=(a[i].val+a[i].val);
	}
	for(int i=1,j=1;j<=3*n;j++)
	{
		ans[max(j-n+1,0LL)]-=b[j].val;
		while(b[j].val>a[i].val&&i<=n) i++;
		//1~i-1 a[i]<=b[j](j-i+2~j)  a[i]>b[j](j-n+1~j-i+1)
		ans[j-i+2]+=b[j].val+b[j].val;
		ans[j+1]-=b[j].val;
	}
	int sum=ans[0],id=0,mi=inf;
	for(int i=1;i<=2*n+1;i++) 
	{
		sum+=ans[i];
		ans[i]+=ans[i-1];
		if(mi>sum)
		{
			mi=sum;
			id=i;
		}
	} 
	cout<<mi<<endl;
	for(int i=1;i<=n;i++) pos[a[i].id]=b[i+id-1].id;
	for(int i=1;i<=n;i++) printf("%d ",pos[i]);
	return 0;
}