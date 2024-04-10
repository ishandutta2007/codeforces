#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int a[maxn];
int n;
int main(){
	cin>>n;
	int sum = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
		sum+=a[i];
	}
	sum = (sum+1)/2;
	int temp =0;
	for (int i=1;i<=n;i++){
		temp+=a[i];
		if (temp>=sum){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}