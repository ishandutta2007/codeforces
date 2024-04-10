#include<bits/stdc++.h>

using namespace std;

const int maxn=2000006;
long long n,k;
long long ys[maxn],ysn=0;

int main(){
	cin>>n>>k;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			ys[++ysn]=i;
			if(i!=n/i) ys[++ysn]=n/i;
		}
	}
	long long cans=0x3fff3fff3fff3fff;
	for(int i=1;i<=ysn;i++){
		if(n/ys[i]>=k) continue;
		long long cur=ys[i]*k+(n/ys[i]);
		if(cur<cans) cans=cur;
	}
	cout<<cans;
	return 0;
}