#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n , mx = 0 , cnt = 0 , r = 0 , l = 0;
		cin>>n;
		deque<int> v(n);
		for(int i = 0 ; i < n ; i++) cin>>v[i];
		while(!v.empty()){
			int cc = 0;
			while(cc <= mx && !v.empty()) cc+= v.front() , v.pop_front();
			if(cc) cnt++;
			mx = cc;
			l+=cc;
			cc = 0;
			while(cc <= mx && !v.empty()) cc+=v.back() , v.pop_back();
			mx = cc;
			if(cc) cnt++;
			r+=cc;
		}
		cout<<cnt<<" "<<l<<" "<<r<<'\n';
	}
}