#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string n;
		cin>>n;
		vector<int> a;
		int cnt = 0;
		for(int i = n.size() - 1 , t = 1 ; i >= 0 ; i-- , t*=10) if(n[i] != '0') a.push_back((n[i] - '0')*t) , cnt++;
		cout<<cnt<<endl;
		for(int i : a) cout<<i<<" ";
		cout<<endl;
	}
}