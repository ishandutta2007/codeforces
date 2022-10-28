#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		int a1;
		int a2;
		if(a<c){
			a1=1;
		}
		else{
			a1=-1;
		}
		if(a*b>c){
			a2=b;
		}
		else{
			a2=-1;
		}
		cout<<a1<<" "<<a2<<endl;
	}
	return 0;
}