#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[200003],ans[400003];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=2;i<=2*k;i++)
			ans[i]=0;
		for(int i=0;i<n/2;i++)
		{
			int x=a[i],y=a[n-1-i];
			if(x>y)swap(x,y);
			ans[2]+=2;
			ans[1+x]-=1;
			ans[x+y]-=1;
			ans[x+y+1]+=1;
			ans[y+k+1]+=1;
		}
		int cnt=0,res=23333333;
		for(int i=2;i<=2*k;i++){
			cnt+=ans[i];
			res=min(res,cnt);
		}
		cout<<res<<endl;
	}
}