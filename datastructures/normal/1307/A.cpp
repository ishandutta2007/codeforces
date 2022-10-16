#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,d,a[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++)cin>>a[i];
		int sum=0;
		for (int i=2;i<=n;i++){
			while(a[i]>0){
				if (sum+(i-1)>d)break;
				a[i]--;
				a[1]++;
				sum+=(i-1);
			}
		}
		cout<<a[1]<<endl;
	}
	return 0;
}