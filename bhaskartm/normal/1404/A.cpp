#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		string st;
		cin>>st;
		int val[k];
		bool che=1;
		for(int i=0; i<k; i++){
			bool c0=0;
			bool c1=0;
			for(int j=i; j<st.size(); j=j+k){
				if(st[j]=='0'){
					c0=1;
				}
				if(st[j]=='1'){
					c1=1;
				}
			}
			if(c0 && c1){
				che=0;
				break;
			}
			else if(c0){
				val[i]=0;
			}
			else if(c1){
				val[i]=1;
			}
			else{
				val[i]=2;
			}
		}
		if(che==0){
			cout<<"NO"<<endl;
			continue;
		}
		int n0=0;
		int n1=0;
		for(int i=0; i<k; i++){
			if(val[i]==0){
				n0++;
			}
			else if(val[i]==1){
				n1++;
			}
		}
		if(n0<=(k/2) && n1<=(k/2)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}