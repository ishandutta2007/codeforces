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
		string st;
		cin>>st;
		int curr=0;
		int ans=0;
		int b=0;
		int a=0;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='A'){
				curr++;
				a++;
			}
			else{
				if(curr==0){
					b++;
				}
				else{
					curr--;
					a--;
				}
			}
		}
		cout<<a+(b%2)<<endl;
	}
	return 0;
}