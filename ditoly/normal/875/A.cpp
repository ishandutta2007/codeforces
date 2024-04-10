#include<cstdio>
#include<vector>
using namespace std;
vector<int> ans;
int main()
{
	int n,i,x,y;
	scanf("%d",&n);
	for(i=100;i;--i)if(i<n)
	{
		for(x=n-i,y=0;x;x/=10)y+=x%10;
		if(y==i)ans.push_back(n-i);
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();++i)printf("%d\n",ans[i]);
}