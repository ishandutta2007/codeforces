#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int ans(int n,int k){
	if(n==0)return 0;
	if(k%3){
		if(n%3)return 1;
		return 0;
	}
	int lo=1;
	int hi=n/3;
	if(hi<lo)return 1;
	while(lo!=hi){
		int mid=(lo+hi)/2;
		if(3*mid+(mid/(k/3))<n){
			lo=mid+1;
		}
		else{
			hi=mid;
		}
	}
	if(3*lo+(lo/(k/3))==n)return 0;
	return 1;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		int n,k;
		cin>>n>>k;
		if(ans(n,k))printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}