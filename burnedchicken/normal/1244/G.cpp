#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;
 
int main(){
	ll n,k;
	cin >> n >> k;
	if(k<n*(n+1)/2){
		cout << -1 << endl;
		return 0;
	}
	if(k==n*(n+1)/2){
		cout << n*(n+1)/2 << endl;
		loop(n) cout << i+1 << " ";
		cout << endl;
		loop(n) cout << i+1 << " ";
		cout << endl;
		return 0;
	}
	if(n%2==0){
		if(k>=(n/2)*(n/2+1+n)){
			cout << (n/2)*(n/2+1+n) << endl;
			loop(n) cout << i+1 << " ";
			cout << endl;
			loop(n) cout << n-i << " ";
			cout << endl;
			return 0;
		}
	}
	if(n%2==1){
		if(k>=(n/2)*(n/2+2+n)+n/2+1){
			cout << (n/2)*(n/2+2+n)+n/2+1 << endl;
			loop(n) cout << i+1 << " ";
			cout << endl;
			loop(n) cout << n-i << " ";
			cout << endl;
			return 0;
		}
	}
	ll a[(n+1)/2];
	a[0]=n*(n+1)/2;
	ll w=n-1;
	loop((n-1)/2){
		a[i+1]=a[i]+w;
		w=w-2;
	}
	ll Min,Max;
	Min=0;
	Max=(n-1)/2;
	while(Max!=Min){
		if(k<=a[(Min+Max+1)/2]) Max=(Min+Max+1)/2-1;
		else Min=(Min+Max+1)/2;
	}
	cout << k << endl;
	ll x=k-a[Min];
	ll v=n-Min-x;
	ll it=n;
	loop(n+1){
		if(i==0) continue;
		if(i<=Min) cout << i << " ";
		else if(i==v) cout << Min+1 << " ";
		else{
			cout << it << " ";
			it--;
		}
	}
	cout << endl;
	loop(n) cout << n-i << " ";
	cout << endl;
	return 0;
}