#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<char> a;
	string b;
	int ans = 0;
	cin>>b;
	for(int i = 0 ; i < b.size() ; i++){
		if(a.empty() || a.top() != b[i]) a.push(b[i]);
		else if(a.top() == b[i]) ans++ , a.pop();
	}
	if(ans % 2 == 0) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}