#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
int t,n,a[205],sum;
int isp(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0,fg=1;
		for (int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
		if (isp(sum)){
			cout<<n-1<<endl;
			for (int i=1;i<=n;i++){
				if (a[i]%2==1&&fg==1){
					fg=0;
					continue;
				}
				cout<<i<<' ';
			}
		}
		else{
			cout<<n<<endl;
			for (int i=1;i<=n;i++)cout<<i<<' ';
		}
		cout<<endl;
	}
	return 0;
}