#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;

string str;

vector <int> a, b;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> str;
	
	n = str.length();
	
	for(i=0;i<n;i++){
		if(str[i] == '0'){
			a.push_back(1);
			cout << 1 << " " << a.size() << endl;
			if(a.size() == 4){
				a.clear();
			}
		}else{
			b.push_back(1);
			cout << 3 << " " << b.size() * 2 - 1 << endl;
			if(b.size() == 2){
				b.clear();
			}
		}
	}
	
	return 0;
}