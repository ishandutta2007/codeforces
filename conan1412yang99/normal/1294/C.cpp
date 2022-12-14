#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	cin>>a;
	while(a--){
		long long b , c;
		cin>>b;
		c = b;
		int k = 0;
		vector<int> v;
		for(int i = 2 ; i < sqrt(b) ; i++){
			if(b%i==0) b/=i , k++ , v.push_back(i);
			if(k == 2) break;
		}
		if(k == 2){
			v.push_back(c/(v[0]*v[1]));
			cout<<"YES"<<endl<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
		}
		else cout<<"NO"<<endl;
	}
}