#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){cin>>T;
	while(T--){long long ans=0;
		cin>>n;for(int i=0;i<n;i++)scanf("%d",a+i);
		int mn[2]={a[0],a[0]},tp;if(a[0]>0)tp=0;else tp=1;
		for(int i=1;i<n;i++)
			if((a[i]>0&&a[i-1]<0)||(a[i]<0&&a[i-1]>0))
				ans+=mn[tp],tp^=1,mn[tp]=a[i];
			else
				mn[tp]=max(mn[tp],a[i]); 
		ans+=mn[tp];cout<<ans<<endl;
	}
}