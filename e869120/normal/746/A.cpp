#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	cout<<min({a,b/2,c/4})*7<<endl;
	return 0;
}