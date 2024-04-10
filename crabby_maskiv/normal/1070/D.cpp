#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

long long n,k;
long long a[maxn];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long lft=0;
	long long ans=0;
	for(int i=1;i<n;i++){
		long long cur=lft;
		cur+=a[i];
		long long ctw=(cur/k)*k;
		ans+=cur/k;
		if(ctw<lft){
			ctw+=k;
			ans++;
		}
		cur-=ctw;
		if(cur<0) lft=0;
		else lft=cur;
	}
	lft+=a[n];
	if(lft%k){
		ans+=lft/k+1;
	}else ans+=lft/k;
	cout<<ans;
	
	return 0;
}