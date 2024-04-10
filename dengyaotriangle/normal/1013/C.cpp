#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=200005;

int n;
long long c[maxn];

int main(){
	cin>>n;
	for(int i=0;i<n+n;i++){
		cin>>c[i];
	}
	sort(c,c+n+n);
	long long ans1=(c[n-1]-c[0])*(c[n+n-1]-c[n]);
	for(int i=0;i<n;i++){
		long long cd=c[i+n]-c[i+1];
		
		ans1=min(ans1,cd*(c[n+n-1]-c[0]));
	}
	cout<<ans1;
	return 0;
}