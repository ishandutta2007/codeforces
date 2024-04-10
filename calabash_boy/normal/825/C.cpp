#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000
long long a[MAXN];
long long n,k;
long long nowMax =-1;
int main(){
	cin>>n>>k;
	int len = 0;
	for (int i=0;i<n;i++){
		long long temp;
		scanf("%I64d",&temp);
		if (temp>k){
			a[len]=temp;
			len++;
		}
	}
	long long ans =0;
	sort(a+0,a+len);
	for (int i=0;i<len;){
		if (a[i]<=k*2){
			k=a[i];
			i++;
		}else{
			ans++;
			k=k*2;
		}
	}
	cout<<ans<<endl;
	return 0;
}