#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long int
#define endl '\n'
int fu(int x){
	int lo=1;
	int hi=1000000;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(mid*mid*mid==x){
			return mid;
		}
		if(mid*mid*mid<x){
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	return -1;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	while(n--){
		int a, b;
		cin>>a>>b;
		
		int c=floor(cbrt(a*b));
		bool che=0;
		if(c*c*c==a*b){
			c=c;
			che=1;
		}
		else if((c+1)*(c+1)*(c+1)==a*b){
			c=c+1;
			che=1;
		}
		else if((c-1)*(c-1)*(c-1)==a*b){
			c=c-1;
			che=1;
		}
		if(che==0){
			cout<<"NO"<<endl;
			continue;
		}
		if(c==-1){
			cout<<"NO"<<endl;
			continue;
		}
		if(a%c==0 && b%c==0){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			cout<<"NO"<<endl;
			continue;
		}
		
	}
	return 0;
}