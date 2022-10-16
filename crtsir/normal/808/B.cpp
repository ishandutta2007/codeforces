#include<bits/stdc++.h>
using namespace std;
long long cnt,cntt,n,k,a[200003];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<k-1;i++)
		cntt+=a[i];
	for(int i=k-1;i<n;i++){
		cntt+=a[i];
		cnt+=cntt;
		cntt-=a[i-k+1];
	}
	printf("%.8f",(cnt*1.0/(n-k+1)));
}