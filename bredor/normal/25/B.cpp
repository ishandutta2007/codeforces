//  228

#include<bits/stdc++.h>
using namespace std;
string k;
int main(){
	int n,i,z=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cout<<k[i];
		z++;
		if(z==2&&i+2<n){
			z=0;
			cout<<"-";
		}
	}
}