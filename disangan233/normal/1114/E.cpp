#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define random() ((rand()*233)%n+1)
int n,t=60,l=0,r=1e9,mid,a[31],b[31],vis[1000005],m;
char qwq;
inline int gcd(re a,re b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	srand(time(0));
	cin>>n;
	while(t>30)
	{
		t--;
		re x;
		mid=(l+r)>>1;
		cout<<"> "<<mid<<endl;
		cin>>x;
		if(x) l=mid+1;
		else r=mid-1;
		if(!(l<=r)) t=30;
		fflush(stdout);
	}
	while(t--)
	{
		re x,rd=random();
		while(vis[rd]) rd=random();
		cout<<"? "<<rd<<endl;
		vis[rd]=1;
		cin>>a[++a[0]];
		if(a[0]==n) break; 
		fflush(stdout);
	}
	sort(a+1,a+a[0]+1);
	for(re i=1;i<a[0];i++) b[i]=a[i+1]-a[i];
	sort(b+1,b+a[0]);
	re ans=b[1];
	for(re i=2;i<a[0];i++)
	ans=gcd(ans,b[i]);
	cout<<"! "<<max(l,r)-ans*(n-1)<<" "<<ans<<endl;
	fflush(stdout);
}