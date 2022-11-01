#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

string str;

bool isc[505];

int main(){
	int i, j;
	
	cin >> str;
	
	for(i=1;i<str.length() - 1;i++){
		for(j=0;j<200;j++){
			isc[j] = false;
		}
		
		isc[str[i - 1]] = true;
		isc[str[i]] = true;
		isc[str[i + 1]] = true;
		
		if(isc['A'] and isc['B'] and isc['C']){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	
	return 0;
}