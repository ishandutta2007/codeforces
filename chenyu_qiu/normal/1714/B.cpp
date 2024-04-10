#include <bits/stdc++.h>
 
 
using namespace std;
 
void solve(){
	
	int n, tmp;
	map<int, int> m;
	vector<int> v;
	
	
	
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(m.find(v[i]) != m.end()){
			ans = max(m[v[i]], ans);	
		}
		m[v[i]] = (i + 1);		
 
	}	
	
 
	cout<< ans <<"\n";
 
}
 
 
 
int main(){
	  
	  // IO Speed Up
	  ios_base::sync_with_stdio(false);
      cin.tie(NULL);
	  
	  int nq;
	  
	  cin>>nq;
	  
	  for(int qi = 1; qi <= nq; qi++){
		  solve();
	  }
	  
	return 0;
}