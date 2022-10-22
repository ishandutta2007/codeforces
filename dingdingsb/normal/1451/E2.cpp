#include<bits/stdc++.h>
using namespace std;
int n;
int a[(1<<16)+10];
int ans[(1<<16)+12];
int lst[(1<<16)];
signed main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cout<<"XOR "<<i-1<<" "<<i<<endl;
		cout.flush();
		int aa;cin>>aa;
		a[i]=a[i-1]^aa;
	}
	for(int i=1;i<=n;i++)
		if(!lst[a[i]])lst[a[i]]=i;
		else{
			//
			cout<<"AND "<<lst[a[i]]<<" "<<i<<endl;
			cout.flush();
			cin>>ans[i];
			for(int j=i-1;j>=1;j--)
				ans[j]=ans[j+1]^a[j+1]^a[j];
			for(int j=i+1;j<=n;j++)
				ans[j]=ans[j-1]^a[j-1]^a[j];
			cout<<"! ";
			for(int j=1;j<=n;j++)
				printf("%d ",ans[j]);
			return 0;
		}
	int k; 
	for(k=1;k<=n;k++)if(a[k]==n-1)break;
	//i1
	//
	memset(lst,0,sizeof lst);
	for(int i=2;i<=n;i++)
		if(i==k)continue;
		else if(lst[(n-1)^a[i]]){
			int jj=lst[(n-1)^a[i]];
			//k
			cout<<"AND "<<k<<" "<<i<<endl;
			cout.flush();
			int tmp;cin>>tmp;
			for(int w=0;w<16;w++)
				if(tmp>>w&1)
					ans[k]+=1<<w;
			cout<<"AND "<<k<<" "<<jj<<endl;
			cout.flush();
			cin>>tmp;
			for(int w=0;w<16;w++)
				if(tmp>>w&1)
					ans[k]+=1<<w;
			for(int j=k-1;j>=1;j--)
				ans[j]=ans[j+1]^a[j+1]^a[j];
			for(int j=k+1;j<=n;j++)
				ans[j]=ans[j-1]^a[j-1]^a[j];
			cout<<"! ";
			for(int j=1;j<=n;j++)
				printf("%d ",ans[j]);
			return 0;
		}else lst[a[i]]=i;
	return 0;
}