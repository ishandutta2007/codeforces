#include<bits/stdc++.h>
using namespace std;
int T,n,x,d[100004];
int a[100004],ans,MAX[10004],MIN[10004];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>x;ans=1e6;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			d[i]=(d[i-1]+a[i])%x;
		}
		for(int i=0;i<10004;i++)MIN[i]=MAX[i]=1e6;
		for(int i=0;i<=n;i++)MAX[d[i]]=min(MAX[d[i]],i),MIN[d[i]]=min(MIN[d[i]],i);
		for(int i=1;i<x;i++)MIN[i]=min(MIN[i-1],MIN[i]);
		for(int i=x-2;i>=0;i--)MAX[i]=min(MAX[i],MAX[i+1]);
		int now=0;
		for(int i=n+1,j=0;i>=0;i--,j++){
			now=(now+a[i])%x;
			int WANT=(d[n]+x-now)%x;
			if(WANT>0){
				int pos=MIN[WANT-1];
				if(i>pos)ans=min(ans,j+pos);
			}
			int pos=MAX[WANT+1];
			if(i>pos)ans=min(ans,j+pos);
		}
		if(ans<1e6)cout<<n-ans<<"\n";
		else puts("-1");
	}
}