#include <bits/stdc++.h>

#define ll long long int
 
using namespace std;

int main(){
	int n,k,id,a;
	cin >> n >> k;
	set<int> s;
	queue<int> q;
	stack<int> sta;
	for(int i=0; i<n; i++){
		cin >> id;
		a=s.size();
		s.insert(id);
		if(s.size()>a){
			q.push(id);
		}
		if(s.size()>k){
			s.erase(q.front());
			q.pop();
		}
	}
	cout << s.size() << endl;
	for(int i=0; i<s.size(); i++){
		sta.push(q.front());
		q.pop();
	}
	for(int i=0; i<s.size(); i++){
		cout << sta.top() << " ";
		sta.pop();
	}
	cout << endl;
	return 0;
}