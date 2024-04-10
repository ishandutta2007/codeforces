#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	cin>>a;
	while(a--){
		int b;
		cin>>b;
		vector<pair<int , int>> v;
		vector<char> p;
		for(int i = 0 ; i < b ; i++){
			int o , oo;
			cin>>o>>oo;
			v.emplace_back(o , oo);
		}
		sort(v.begin() , v.end());
		int time = 0 , track = 0 , yy = 0 , t = b;
		for(int i = 0 ; i <= v[b-1].first ; i++){
			if(i == v[time].first){
				if(track <= v[time].second){
					while(i == v[time].first){
						for(int t = track ; t < v[time].second ; t++) p.push_back('U');
						track = v[time].second , time++ , t--;
					}
				}
				else{cout<<"NO"<<endl;yy = 1;break;}
			}
			if(t > 0) p.push_back('R');
		}
		if(yy == 0){
			cout<<"YES"<<endl;
			for(int i = 0 ; i < p.size() ; i++) cout<<p[i];
			cout<<endl;
		}
	}
}