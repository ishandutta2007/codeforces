#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[505],n,q;
int main(){
//	freopen("1203B.in","r",stdin);
//	freopen("1203B.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		int flag=1;
		for (int i=1;i<=4*n;i++)cin>>a[i];
		sort(a+1,a+1+4*n);
		for (int i=2;i<=4*n;i+=2)
			if (a[i]!=a[i-1])flag=0;
		int l=1,r=4*n;
		int s=a[l]*a[r];
		while(l<=r){
			if (a[l]*a[r]!=s)flag=0;
			l+=2,r-=2;
		}
		if (flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}