#include<bits/stdc++.h>
using namespace std;
struct Seg{
	int l,r;
}seg[305];
int arr[305];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<m;i++)
		scanf("%d%d",&seg[i].l,&seg[i].r);
	int ans=0;
	vector<int> used;
	for(int i=1;i<=n;i++)
	{
		int ma=arr[i];
		for(int j=1;j<=n;j++)
		{
			vector<int> tmp;
			if(i==j) continue;
			int cur=ma-arr[j];
			for(int k=0;k<m;k++)
			{
				if(seg[k].l<=i&&seg[k].r>=i) continue;
				if(seg[k].l<=j&&seg[k].r>=j) {
					cur++;tmp.push_back(k);
				}
			}
			if(cur>ans)
			{
				ans=cur;
				used=tmp;
			}
		}
	}
	printf("%d\n",ans);
	printf("%d\n",(int)used.size());
	for(auto &p:used) printf("%d ",p+1);
	puts("");
}