#include<iostream>
#include<vector>
using namespace std;
int n;vector<int>x;
int main(){
	cin>>n;
	for(int i=1;i<=1000;i++){
		if(n>=i+(i+1))x.push_back(i);
		else{x.push_back(n);break;}
		n-=i;
	}
	cout<<x.size()<<endl;
	for(int i=0;i<x.size();i++){if(i)cout<<' ';cout<<x[i];}
	cout<<endl;
	return 0;
}