#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	if(((n)*(n-1))/2<k){
		cout<<"Impossible";
		return 0;
	}
	int tot=0;
	int lay=n;
	int rem=((n*(n-1))/2)-k;
	int reml=-1;
	while(1){
		if(rem==reml){
			break;
		}
		if(rem==0){
			break;
		}
		reml=rem;
		if(lay-1<=rem){
			lay--;
			rem-=lay;
			tot++;
			continue;
		}
		else{
			
		}
	}
	if(rem==0){
		
		for(int i=0; i<lay; i++){
			cout<<"(";
		}
		for(int i=0; i<lay; i++){
			cout<<")";
		}
		for(int i=0; i<tot; i++){
			cout<<"(";
			cout<<")";
		}
		return 0;
	}
	
	for(int i=0; i<lay-1-rem; i++){
		cout<<"(";
	}
	cout<<"(";
	cout<<")";
	for(int i=0; i<rem; i++){
		cout<<"(";
	}
	for(int i=0; i<lay-1; i++){
		cout<<")";
	}
	for(int i=0; i<tot; i++){
		cout<<"()";
	}
	return 0;
	return 0;
}