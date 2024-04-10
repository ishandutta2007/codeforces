#include<bits/stdc++.h>
using namespace std;
long long T,n,t[100003],x[100003],w[100003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(long long i=0;i<n;i++)
			scanf("%lld%lld",t+i,x+i);
		long long atleast=0,lstp=0,ans=0,k,lstt=0,lstm=0;
		for(long long i=0;i<n;i++)
			if(atleast<=t[i]){
				w[i]=lstp;
				lstm=t[i];
				atleast=t[i]+fabs(lstp-x[i]);
				if(lstp<x[i])k=1;else k=-1;
				lstt=lstp;lstp=x[i];
			}else
				w[i]=lstt+k*(t[i]-lstm);
		w[n]=lstp;
		for(long long i=0;i<n;i++)
			if((w[i]<=x[i]&&x[i]<=w[i+1])||(w[i+1]<=x[i]&&x[i]<=w[i]))
				ans++;
		cout<<ans;
		printf("\n");
	}
}