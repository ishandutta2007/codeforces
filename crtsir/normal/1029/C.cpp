#include<bits/stdc++.h>
using namespace std;
int a[300003],b[300003],n,len,c[300003],d[300003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i],
		c[i]=a[i],
		d[i]=b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++){
		int l=a[n-1],r=b[0];
		if(a[n-1]==c[i])
			l=a[n-2];
		if(b[0]==d[i])
			r=b[1];
		len=max(len,r-l);
	}
	cout<<len;
}