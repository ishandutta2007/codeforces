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
		int a, b;
		cin>>a>>b;
		int pl1=(a+b+1)/2;
		int pl2=(a+b)/2;
		set<int>se;
		
		for(int i=0; i<=a; i++){
			int pl=a-i;
			int pl3=pl2-pl;
			if(pl3>=0 && pl3<=b){
				se.insert(pl+b-pl3);
			}
		}
		swap(pl1, pl2);
		for(int i=0; i<=a; i++){
			int pl=a-i;
			int pl3=pl2-pl;
			if(pl3>=0 && pl3<=b){
				se.insert(pl+b-pl3);
			}
		}
		cout<<se.size()<<endl;
		for(auto u:se){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}