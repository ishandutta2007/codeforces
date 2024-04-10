#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;



int main(){
	int t, a, b, c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		long long C = 1, A, B;
		while(size(to_string(C)) < c){
			C *= 7;
		}
		A = B = C;
		while(size(to_string(A)) < a)
			A *= 2;
		
		while(size(to_string(B)) < b)
			B *= 3;

		cout<<A<<' '<<B<<'\n';
	}
}