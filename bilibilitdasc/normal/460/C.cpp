#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int main()
{
	int n,m,w;
	cin>>n>>m>>w;
	vector<int> a(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	long long l=0,u=1000000000+100000;
	while(u-l>0){
		long long mid=(u+l+1)/2;
		vector <long long> dif(n);
		long long cnt=0;
		long long cur=0;
		rep(i,n)
		{
			cur-=dif[i];
			long long x=mid-a[i]-cur;
			if(x>0)
			{
				cnt+=x;
				cur+=x;
				if(i+w<n) dif[i+w]+=x;
			}
			
		}
		if(cnt<=m)
			l=mid;
		else
			u=mid-1;
	}
	printf("%d\n",(int)l);
	return 0;
}