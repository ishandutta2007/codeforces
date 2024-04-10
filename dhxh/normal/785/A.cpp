#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

string str;

int main(){
	int i, j;
	int ans = 0;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str;
		if(str == "Tetrahedron"){
			ans += 4;
		}else if(str == "Cube"){
			ans += 6;
		}else if(str == "Octahedron"){
			ans += 8;
		}else if(str == "Dodecahedron"){
			ans += 12;
		}else if(str  == "Icosahedron"){
			ans += 20;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}