#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n-(n+3)/4;i++)printf("9");
		for(int i=0;i<=(n-1)/4;i++)printf("8");cout<<endl;
	}
}