#include<bits/stdc++.h>
using namespace std;
int n,a[8003],T,hav[8003]; 
int main(){
	cin>>T;
	while(T--){
		for(int i=0;i<8003;i++)
			hav[i]=0;
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<n;i++){
			int cnt=a[i];
			for(int j=i+1;j<n;j++){
				cnt+=a[j];
				if(cnt>n)continue;
				hav[cnt]=1;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=hav[a[i]];cout<<ans<<endl;
	} 
}