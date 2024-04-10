#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define MOD 1000000007
int x[MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if (n==2){
		int temp = x[1]-x[0];
		if (temp<0){
			temp=-temp;
		}
		cout<<temp;
		return 0;
	}
	sort(x+0,x+n);
//	for (int i=0;i<n;i++){
//		printf("%d ",x[i]);
//	}
	long long tt = 1;
	long long ans1 =0;
	for (int i=0;i<n;i++){
		long long temp = tt*x[i];
		temp%=MOD;
		ans1+=temp;
		if (ans1>MOD){
			ans1-=MOD;
		}
		tt<<=1;
		if (tt>MOD){
			tt-=MOD;
		}
	}
//	ans1-=x[n-1];
	long long ans2 =0;
	tt=1;
	for (int i=n-1;i>=0;i--){
		long long  temp = tt*x[i];
		temp%=MOD;
		ans2+=temp;
		if (ans2>MOD){
			ans2-=MOD;
		}
		tt<<=1;
		if (tt>MOD){
			tt-=MOD;
		}
	}
//	ans1-=x[0];
//	cout<<ans1<<" "<<ans2<<endl;
	long long ans = ans1-ans2;
	ans+=MOD;
	ans+=MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}