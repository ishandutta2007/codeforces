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
int sumx,sumy,n,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		sumx+=t;
	}
	for(int i=0;i<n;i++){
		cin>>t;
		sumy+=t;
	}
	if(sumx>=sumy){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}