#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
long long x[maxn];
long long ans=0x7FFFFFFFFFFFFFFF,cnt=0;

long long absl(long long a){
	if(a<0) return 0-a;
	return a;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	sort(x,x+n);
	for(int i=1;i<n;i++){
		if(absl(x[i-1]-x[i])<ans){
			ans=absl(x[i-1]-x[i]);
			cnt=1;
		}else if(absl(x[i-1]-x[i])==ans){
			cnt++;
		}
	}
	cout<<ans<<' '<<cnt;
	return 0;
}