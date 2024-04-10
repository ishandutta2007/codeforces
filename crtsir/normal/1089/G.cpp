#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,a[7];
	cin>>t;
	while(t--){
		cin>>n;
		int cnt=0;
		for(int i=0;i<7;i++){
			cin>>a[i];
			cnt+=a[i];
		}
		//cout<<cnt<<' ';
		long long res=12345678901234,tmp=n;
		for(int i=0;i<7;i++)
			if(a[i])
			{
				n=tmp;
				long long ans=0;
				for(int j=i;j<7&&n;j++)
					n-=a[j],
					ans++;
				if(n==0){res=min(ans,res);continue;}
				ans=ans+7*(n/cnt)-7;
				//if(i==1)cout<<ans<<endl;
				n=n%cnt+cnt;
				int j=0;
				while(n)
					n-=a[(j++)%7],
					ans++;
				//cout<<ans<<endl;
				res=min(ans,res);
			}
		cout<<res<<endl;
	}
}