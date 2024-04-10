#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string a;

int b[] = {8, -1, -1, 3, 6, 9, 4, 7, 0, 5};

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> a;
	
	for(i=0;i<a.length();i++){
		if(b[a[i] - '0'] != a[a.length() - i - 1] - '0'){
			cout << "No" <<endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	
	return 0;
}