#include<bits/stdc++.h>
int main()
{
	int T,n;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		std::vector<double>V1,V2;
		for(int i=1,x,y;i<=2*n;++i)
		{
			scanf("%d%d",&x,&y);
			if(x==0)V1.push_back(abs(y));
			else V2.push_back(abs(x));
		}
		
		std::sort(V1.begin(),V1.end());
		std::sort(V2.begin(),V2.end());
		
		double ans=0;
		for(int i=0;i<n;++i)
		ans+=sqrt(1.*V1[i]*V1[i]+1.*V2[i]*V2[i]);
		printf("%.15f\n",ans);
	}
	return 0;
}