#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<int>f;
	for(int i=1; i*i<=m; i++){
		if(m%i==0 && i*i!=m){
			f.push_back(i);
			f.push_back(m/i);
		}
		else if(i*i==m){
			f.push_back(i);
		}
	}
	
	sort(f.begin(), f.end());

	map<int, int>gr;
	for(int i=0; i<f.size(); i++){
		int val=f[i];
		if(val<k){
			gr[val]=0;
			
			continue;
		}
		set<int>s;
		for(int j=0; j<i; j++){
			if(f[i]%f[j]!=0 || f[j]<k){
				continue;
			}
			
			int num=(f[i]/f[j]);
			
			if(num%2==0){
				s.insert(0);
			}
			else{
				s.insert(gr[j]);
			}
		}
		
		if(s.empty()){
			gr[val]=0;
			continue;
		}
		vector<int>che;
		for(auto it=s.begin(); it!=s.end(); it++){
			che.push_back((*it));
		}
		if(che[che.size()-1]==che.size()-1){
			gr[f[i]]=che.size();
			continue;
		}
		for(int i=0; i<che.size(); i++){
			if(che[i]!=i){
				gr[f[i]]=i;
				break;
			}
		}
	}
	
	if(n%2==0 || gr[m]==0 || m<k){
		cout<<"Marsel"<<endl;
	}
	else{
		cout<<"Timur"<<endl;
	}
	
	return 0;
}