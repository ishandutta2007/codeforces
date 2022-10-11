#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],b[100000],ret=0;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	sort(a,a+n);sort(b,b+m);
	for(int i=0;i<n;i++){
		int pos1=lower_bound(b,b+m,a[i])-b;
		int minx=2e9;
		if(pos1!=m){minx=min(minx,abs(a[i]-b[pos1]));}
		if(pos1!=0){minx=min(minx,abs(a[i]-b[pos1-1]));}
		ret=max(ret,minx);
	}
	cout<<ret<<endl;
	return 0;
}