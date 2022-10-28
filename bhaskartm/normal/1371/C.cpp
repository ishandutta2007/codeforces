#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a, b, n, m;
		cin>>a>>b>>n>>m;
		if(n+m>a+b){
			cout<<"NO"<<endl;
			continue;
		}
		int gap=abs(a-b);
		if(n>=gap){
			a=min(a, b);
			b=min(a, b);
			n=n-gap;
			int val=min(n, m);
			a=a-val;
			b=b-val;
			n=n-val;
			m=m-val;
			if(n==0){
				if(a>=m){
					cout<<"YES"<<endl;
					continue;
				}
				else{
					cout<<"NO"<<endl;
					continue;
				}
			}
			if(m==0){
				if(a+b>=n){
					cout<<"YES"<<endl;
					continue;
				}
				else{
					cout<<"NO"<<endl;
					continue;
				}
			}
		}
		else{
			if(a>b){
				a=a-n;
			}
			else{
				b=b-n;
			}
			n=0;
			if(m<=min(a, b)){
				cout<<"YES"<<endl;
				continue;
			}
			else{
				cout<<"NO"<<endl;
				continue;
			}
		}
		
		
	}
	return 0;
}