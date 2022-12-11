#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> ans;
int main()
{
	long long n,i,l,r,mid;
	scanf("%lld",&n);
	for(i=1;i<=n+1;i<<=1)
		for(l=0,r=1e18;l<=r;)
		{
			mid=l+r>>1;
			if(mid-1+i>n/(2*mid+1)){r=mid-1;continue;}
			if((2*mid+1)*(mid-1+i)==n){ans.push_back((2*mid+1)*i);break;}
			l=mid+1;
		}
	sort(ans.begin(),ans.end());
	if(ans.empty())return 0*puts("-1");
	for(i=0;i<ans.size();++i)printf("%I64d\n",ans[i]);
}