#include<iostream>
#include<vector>
using namespace std;
#define R register int
inline bool Check(int x){
	for(R i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	vector<int>A;
	for(int i=2;A.size()<1000;i++){
		if(Check(i)==true){
			A.push_back(i);
		}
	}
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		cin>>t;
		for(R j=0;j!=t;j++){
			cout<<A[j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}