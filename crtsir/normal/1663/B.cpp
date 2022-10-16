#include<bits/stdc++.h>
using namespace std;
int ln[9]={1200,1400,1600,1900,2100,2300,2400,2600,3000},x;
int main(){
	cin>>x;
	for(int i=0;i<9;i++)
		if(ln[i]>x){
			cout<<ln[i];
			break;
		}
}