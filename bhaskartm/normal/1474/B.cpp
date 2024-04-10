#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
bool pr[30000];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2; i<30000; i++){
		bool che=1;
		for(int j=2; j*j<=i; j++){
			if(i%j==0){
				che=0;
				break;
			}
		}
		if(che){
			pr[i]=1;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int num1=1+n;
		while(!pr[num1]){
			num1++;
		}
		int num2=num1+n;
		while(!pr[num2]){
			num2++;
		}
		cout<<num1*num2<<endl;
	}
	return 0;
}