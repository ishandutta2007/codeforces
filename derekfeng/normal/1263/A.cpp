#include <bits/stdc++.h>
using namespace std;
int n,r,g,b;
int main(){
	cin>>n;
	while (n--){
		cin>>r>>g>>b;
		cout<<min((r+g+b)/2,r+g+b-max(b,max(r,g)))<<"\n";
	}
}