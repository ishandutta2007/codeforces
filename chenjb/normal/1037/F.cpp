#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
#define MOD 1000000007
using namespace std;
int a[2000000],n,k;
set<int>dic;
int q[2000000];
bool cmp(int x,int y){ return a[x]>a[y]; }
long long get(int x)  //subnb!!!!! Contribution Formula
{
	if(x<=0)return 0;
	return (1ll*(1ll*x+x-1ll*(x/k)*k)*((x/k)+1)/2)%MOD;
}
int main()
{
	cin>>n>>k; k--;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	dic.clear();	
	dic.insert(0);
	dic.insert(n+1);

	for(int i=1;i<=n;i++)q[i]=i;
	sort(q+1,q+n+1,cmp);

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		dic.insert(q[i]);

		int pre; auto it1=dic.find(q[i]);--it1;pre=*it1;
		int suc; auto it2=dic.find(q[i]);++it2;suc=*it2;

		int t1=max(pre+1,q[i]-k);
		int t2=min(q[i],suc-k-1);
		if (t1<=t2)
		{
			long long tmp1=get(suc-k-1-pre); // for ty1
			long long tmp2=get(suc-k-1-q[i]); // for ty2
			long long tmp3=get(q[i]-k-1-pre); //
			tmp1=tmp1-tmp2;
			tmp1=((tmp1%MOD)+MOD)%MOD;
			long long tmp=tmp1-tmp3;
			tmp=((tmp%MOD)+MOD)%MOD;
			tmp%=MOD;
			ans=(ans+1ll*tmp*a[q[i]])%MOD;
		}
	}

	cout<<ans<<endl;
	return 0;
}