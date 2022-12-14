#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n <= 3) cout<<-1<<endl;
		else{
			deque<int> a;
			a.push_back(3) , a.push_back(1) , a.push_back(4) , a.push_back(2);
			for(int i = 5 ; i <= n ; i++) if(i % 2 == 0) a.push_back(i);else a.push_front(i);
			for(int i : a) cout<<i<<" ";
			cout<<endl;
		}
	}
}