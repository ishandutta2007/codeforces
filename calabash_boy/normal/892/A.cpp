#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int a[maxn],b[maxn],n;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for (int i=0;i<n;i++){
		scanf("%d",b+i);
	}
	long long sum =0;
	for (int i=0;i<n;i++){
		sum+=a[i];
	}
	sort(b,b+n);
	long long tot = b[n-1]+b[n-2];
	if (sum<=tot){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}