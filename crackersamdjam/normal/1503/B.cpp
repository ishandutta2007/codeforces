#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 105;

int n;
queue<pair<int, int>> q[2];

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			q[(i+j)%2].push({i, j});
		}
	}
	// 1 2
	for(int t = 0; t < n*n; t++){
		int v; cin>>v;
		if(v == 1){
			//try two
			if(size(q[1])){
				auto [a, b] = q[1].front(); q[1].pop();
				cout<<"2 "<<a<<' '<<b<<endl;
			}
			else{
				//can place 3 in any of the 1 places
				auto [a, b] = q[0].front(); q[0].pop();
				cout<<"3 "<<a<<' '<<b<<endl;
			}
		}
		else if(v == 2){
			//try one
			if(size(q[0])){
				auto [a, b] = q[0].front(); q[0].pop();
				cout<<"1 "<<a<<' '<<b<<endl;
			}
			else{
				auto [a, b] = q[1].front(); q[1].pop();
				cout<<"3 "<<a<<' '<<b<<endl;
			}
		}
		else{
			if(size(q[1])){
				auto [a, b] = q[1].front(); q[1].pop();
				cout<<"2 "<<a<<' '<<b<<endl;
			}
			else{
				auto [a, b] = q[0].front(); q[0].pop();
				cout<<"1 "<<a<<' '<<b<<endl;
			}
		}
	}
}