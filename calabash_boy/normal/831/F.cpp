#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
long long height[MAXN];
long long n,k;
long long ans =1;
bool check(long long day){
	long long num = 0;
	for (int i=0;i<n;i++){
		num+=(height[i]+day-1)/day;
	}
//	cout<<"check("<<day<<"):"<<(num<=k/day)<<endl;
	return num<=k/day;
}
int main (){
	cin>>n>>k;
//	freopen("output.txt","w",stdout);
	for (int i=0;i<n;i++){
		cin>>height[i];
		k+=height[i];
	}
	for (long long i=1,j;i<=k;i=j+1){
		j = k/(k/i);
		if (check(j)){
			ans = j;
		}
	}
	cout<<ans<<endl;
	return 0;
}