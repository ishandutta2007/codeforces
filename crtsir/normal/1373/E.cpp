#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n,k;
	cin>>T;while(T--){
		cin>>n>>k;
		int a=n+k*(k+1)/2;
		if(a%(k+1)==0)
		{
			a/=(k+1);	
			long long res=a%9;
			for(int i=9;i<=a;i+=9)res=res*10+9;
			res-=k;if(res>=0)cout<<res<<endl;else cout<<-1<<endl;
			continue;
		}
		long long res=9223372036854775807; 
		for(int i=1;i<=k;i++)
			for(int j=0;j<10;j++){
				a=n+i*j*9;
				a+=k*(k+1)/2;
				if(a%(k+1))continue;
				a/=(k+1);a-=k;
				if(9*j+i-k>a)continue;
				a=a-9*j-i+k;
				long long tmp=(a+(a>8))%9;
				for(int l=9;l<=a-8;l+=9)tmp=tmp*10+9;
				if(a>8)tmp=tmp*10+8;
				for(int l=1;l<j;l++)tmp=tmp*10+9;tmp=tmp*10+9+i-k;
				res=min(res,tmp);
			}
		if(res<9223372036854775807)
			cout<<res<<endl;
		else
			cout<<-1<<endl;
	}
}