#include<bits/stdc++.h>
using namespace std;
map<int,int> ans;
vector<int> two;
int arr[]={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
	int cur=0;
	for(int i=3;i<(1<<25);i=((i+1)<<1)-1)
	{
		ans[i]=arr[cur++];
		two.push_back(i);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		if(ans.count(n))
			printf("%d\n",ans[n]);
		else{
			printf("%d\n",two[lower_bound(two.begin(),two.end(),n)-two.begin()]);
		}
	}
}