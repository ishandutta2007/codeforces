#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

string home;

string f[1005];

int main(){
	int i, j;
	
	cin >> n;
	cin >> home;
	
	for(i=1;i<=n;i++){
		cin >> f[i];
	}
	
	if(n % 2){
		cout << "contest" << endl;
	}else{
		cout << "home" << endl;
	}
	
	return 0;
}