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
		string st;
		cin>>st;
		int e2=0;
		int o2=0;
		int e1=0;
		int o1=0;
		for(int i=0; i<st.size(); i=i+2){
			if((st[i]-'0')%2==0){
				e2++;
			}
			else{
				o2++;
			}
		}
		for(int i=1; i<st.size(); i=i+2){
			if((st[i]-'0')%2==0){
				e1++;
			}
			else{
				o1++;
			}
		}
		if(n%2==1){
			if(o2!=0){
				cout<<1<<endl;
				
			}
			else{
				cout<<2<<endl;
			}
		}
		else{
			if(e1!=0){
				cout<<2<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}