#include<bits/stdc++.h>
using namespace std;
int become(string s){
	if(s=="Tetrahedron")return 4;
	if(s=="Cube")return 6;
	if(s=="Octahedron")return 8;
	if(s=="Dodecahedron")return 12;
	if(s=="Icosahedron")return 20;
}
int main(){
	int n,a=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		a+=become(s);
	}
	cout<<a;
}