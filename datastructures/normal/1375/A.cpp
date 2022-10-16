#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,a[10005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=n;
		for (int i=1;i<=n;i++){
			if (i&1)cout<<abs(a[i])<<' ';
			else cout<<-abs(a[i])<<' ';
		}
		cout<<endl;
	}
	return 0;
}