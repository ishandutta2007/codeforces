#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int n;
bool isp(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	cin>>n;
	if(n<3){
		cout<<1<<endl;
	}else{
		cout<<2<<endl;
	}
	for(int i=1;i<=n;i++){
		if(!isp(i+1)){
			cout<<2<<' ';
		}else{
			cout<<1<<' ';
		}
	}
	return 0;
}