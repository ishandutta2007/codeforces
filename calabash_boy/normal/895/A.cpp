#include<bits/stdc++.h>
using namespace std;
const int maxn  = 1000;
int a[maxn];
int n;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		a[n+i] =a[i];
	}
	int ans = 360;
	for (int i=0;i<n;i++){
		int temp =0;
		for (int j = i;j<i+n;j++){
			temp+=a[j];
			ans = min(ans,abs(360-2*temp));
		}
	}
	cout<<ans<<endl;
	return 0;
}