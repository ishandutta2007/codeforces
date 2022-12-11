#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define MN 100000
char s[MN+5];
vector<int> a,b;
int cal(int l,int x,int r)
{
	int a=x-l,b=r-x;
	return 2*min(a,b)+max(a,b); 
}
int main()
{
	int n,i,j,l,r,mid,ans,L,R;
	scanf("%d%s",&n,s);
	for(i=0;i<n;++i)
	{
		if(s[i]=='P')a.push_back(i);
		if(s[i]=='*')b.push_back(i);
	}
	for(l=0,r=2*n;l<=r;)
	{
		mid=l+r>>1;
		for(i=j=0;i<a.size();++i)
			for(L=R=a[i];j<b.size();++j)
				if(cal(min(L,b[j]),a[i],max(R,b[j]))>mid)break;
				else L=min(L,b[j]),R=max(R,b[j]);
		if(j<b.size())l=mid+1;
		else r=mid-1,ans=mid;
	}
	printf("%d",ans);
}