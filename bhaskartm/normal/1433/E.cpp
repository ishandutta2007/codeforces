#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'




int f(int x){
	int val=1;
	for(int i=1; i<=x; i++){
		val=val*i;
	}
	return val;
}



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	if(n==2){
		cout<<1;
		return 0;
	}
	if(n==4){
		cout<<3;
		return 0;
	}
	
	cout<<((f(n))/(2*f(n/2)*f(n/2)))*f((n/2)-1)*f((n/2)-1)<<endl;
	
	return 0;
}