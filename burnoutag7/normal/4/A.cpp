/******************
*  Writer: BD747  *
******************/
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	
	_sleep(450);
	if(n>2 && n%2==0){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	return 0;
}