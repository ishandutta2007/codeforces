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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1 || n==2 || n==4){
			cout<<-1<<endl;
			continue;
		}
		int a=0;
		int b=0;
		int c=0;
		while(1){
			if(n==0){
				break;
			}
			if(n%3==0){
				
				a+=(n/3);
				n=0;
				continue;
			}
			if(n%5==0){
				
				b+=(n/5);
				n=0;
				continue;
			}
			if(n%7==0){
				
				c+=(n/7);
				n=0;
				continue;
			}
			else{
				a++;
				n-=3;
			}
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}