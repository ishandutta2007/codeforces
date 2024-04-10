#include<bits/stdc++.h>
using namespace std;
int T,n,k,ans[303][303];
int main(){
	cin>>T;while(T--){
		cin>>n>>k;memset(ans,0,sizeof(ans));
		if(k%n)cout<<2<<endl;else cout<<0<<endl;
		int a=k/n;
		for(int i=0,j=0;i<n;i++)
			for(int kk=0;kk<a+(i<k%n);j=(j+1)%n,kk++)
				ans[i][j]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cout<<ans[i][j];
			cout<<endl;
		}
	}
}