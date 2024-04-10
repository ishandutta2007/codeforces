#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int l,r,y,z;
	bool t=true;
	cin >> l >> r;
	vector<int> x;
	bool a[10];
	for(int i=l; i<=r; i++){
		z=y=i;
		x.clear();
		for(int j=0; j<10; j++){
			a[j]=false;
		}
		while(1){
			x.push_back(y%10);
			y=y/10;
			if(y==0) break;
		}
		for(int j=0; j<x.size(); j++){
			if(a[x.at(j)]){
				break;
			}
			a[x.at(j)]=true;
			if(j==x.size()-1) t=false;
		}
		if(not t) break;
	}
	if(t) cout << -1 << endl;
	else cout << z << endl;
	return 0;
}