#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,a[100003],cnt[100003],pw[100003];
int main(){
	for(int i=1;i<100003;i++)
		pw[i]=((pw[i-1]*2)%mod+1)%mod;
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++){
		int tmp=a[i],x=2,real=1;
		while(x<=sqrt(tmp)){
			if(tmp%x==0){
				while(tmp%x==0)tmp/=x;
				real*=x;
			}
			x++;
		}
		if(tmp!=1)real*=tmp;
		for(int j=1;j<=sqrt(real);j++)
			if(real%j==0){
				cnt[j]++;
				if(j*j!=real)
					cnt[real/j]++;
			}
	}
	int ans=0;
	for(int i=1;i<=100000;i++){
		bool tp=0;int tmp=i,x=2;
		while(x<=sqrt(tmp)){
			if(tmp%x==0){
				while(tmp%x==0)tmp/=x;
				tp^=1;
			}
			x++;
		}
		if(tmp!=1)tp^=1;
		if(tp==0)
			ans=(ans+pw[cnt[i]])%mod;
		else
			ans=((ans-pw[cnt[i]])%mod+mod)%mod;
	}
	cout<<ans;
}