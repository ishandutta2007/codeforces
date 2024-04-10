#include <bits/stdc++.h>
using namespace std;
int n,a[103],b[103];
int main(){
	int T;cin>>T;
	while (T--){
		cin>>n;
		for (int i=0;i<n;i++) cin>>a[i];
		sort (a,a+n);
		for (int i=0;i<n;i++) cout<<a[i]<<" ";puts("");
		for (int i=0;i<n;i++) cin>>a[i];
		sort (a,a+n);
		for (int i=0;i<n;i++) cout<<a[i]<<" ";puts("");
	}
}