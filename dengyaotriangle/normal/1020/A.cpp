#include<bits/stdc++.h>

using namespace std;

long long n,h,a,b,k;

long long absl(long long n){
	if(n<0) return 0-n;
	return n;
}

long long mins(long long a,long long b){
	if(a<b) return a;
	return b;
}
int main(){
	cin>>n>>h>>a>>b>>k;
	while(k--){
		long long t1,f1,t2,f2,a1,a2;
		cin>>t1>>f1>>t2>>f2;
		if(t1==t2){
			cout<<absl(f1-f2)<<endl;
			continue;
		}
		if(f1<=b&&f1>=a&&f2<=b&&f2>=a){
			cout<<absl(t1-t2)+absl(f1-f2)<<endl;
			continue;
		}
		if(f1>b&&f2>b){
			cout<<absl(t1-t2)+absl(f1-b)+absl(f2-b)<<endl;
			continue;
		}
		if(f1<a&&f2<a){
			cout<<absl(t1-t2)+absl(f1-a)+absl(f2-a)<<endl;
			continue;
		}
		cout<<absl(t1-t2)+mins(absl(f1-a)+absl(f2-a),absl(f1-b)+absl(f2-b))<<endl;
	}
	return 0;
}