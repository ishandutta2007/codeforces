#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		long long ans=0;
		if(l%2==1)
		{
			if(r%2==0)
				ans=(r-l+1)/2;
			else{
				ans=(r-l)/2-r;
			}
		}
		else{
			if(r%2==0)
				ans=-(r-l)/2+r;
			else{
				ans=-(r-l+1)/2;
			}
		}
		cout<<ans<<endl;
	}
}