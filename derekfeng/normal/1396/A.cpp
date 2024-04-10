#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100004];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	if(n==1){
		for(int i=0;i<2;i++)puts("1 1\n0");
		puts("1 1"),cout<<(-1)*a[1];
		return 0;
	}
	cout<<"1 "<<n<<endl;
	for(int i=1;i<=n;i++){
		cout<<(-1)*a[i]*n<<" ";
	}
	puts("");
	cout<<"1 "<<n-1<<endl;
	for(int i=1;i<n;i++)cout<<a[i]*(n-1)<<" ";
	puts("");
	cout<<n<<" "<<n<<"\n";
	cout<<a[n]*(n-1)<<endl;
}