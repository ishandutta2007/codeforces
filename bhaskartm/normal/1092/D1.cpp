#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int

 main() {
	int n;
	cin>>n;
	stack<int>s;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		x=x%2;
		if(!s.empty() && s.top()==x){
			s.pop();
		}
		else{
			s.push(x);
		}
	}
	if(s.size()<=1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}