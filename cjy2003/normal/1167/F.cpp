#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void pl(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int n,ans;
struct node
{
	int va,id;
	friend bool operator < (node a,node b){return a.va<b.va;}
}p[500050];
struct BIT
{
	int sum[500050];
	void add(int p,int w){while(p<=n)pl(sum[p],w),p+=p&-p;}
	int query(int p)
	{
		int s=0;
		while(p)pl(s,sum[p]),p-=p&-p;
		return s;
	}
}t1,t2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i].va),p[i].id=i;
	sort(p+1,p+1+n);
	for(int i=1;i<=n;++i)
	{
		t1.add(p[i].id,p[i].id);	
		
	//	pl(ans,1ll*(t1.query(p[i].id)+1)*(t2.query(n)+mod-t2.query(p[i].id-1)+1)%mod*p[i].va%mod);
		pl(ans,1ll*t1.query(p[i].id)*(n-p[i].id+1)%mod*p[i].va%mod);
		pl(ans,1ll*(t2.query(n)+mod-t2.query(p[i].id-1))*p[i].id%mod*p[i].va%mod);
		t2.add(p[i].id,n+1-p[i].id);
	}
	printf("%d",ans);
	return 0;
}