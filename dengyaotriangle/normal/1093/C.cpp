#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;

int n;
long long b[maxn],a[maxn];
int main(){
	cin>>n;
	for(int i=1;i+i<=n;i++) cin>>b[i];
	a[1]=0;
	a[n]=b[1];
	for(int i=2;i+i<=n;i++){
		a[i]=0;
		a[n-i+1]=b[i];
		if(a[i]<a[i-1]){
			long long c=a[i-1]-a[i];
			a[i]+=c;
			a[n-i+1]-=c;
		}
		if(a[n-i+1]>a[n-i+2]){
			long long c=a[n-i+1]-a[n-i+2];
			a[i]+=c;
			a[n-i+1]-=c;
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0; 
}