#include<bits/stdc++.h>
using namespace std;
int l[110],r[110];
int main()
{
	int ans=0;
	int n,p1,p2,p3,t1,t2;
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		ans += (r[i]-l[i])*p1;
		if(i>1)
		{
			if(l[i] - r[i-1] > t1)
			{
				ans += t1*p1;
				int tmp = l[i]-r[i-1]-t1;
				if(tmp>t2) 
				{
					ans += t2*p2;
					ans +=(tmp-t2)*p3;
				}
				else ans += tmp*p2;
			}
			else ans += (l[i]-r[i-1])*p1;
		}
	}
	cout<<ans<<endl;
	return 0;
}