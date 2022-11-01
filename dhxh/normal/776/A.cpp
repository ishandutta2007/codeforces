#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct killbox {
	string a[2];
	
	int kill(string y, string x){
		if(a[0] == x){
			a[0] = y;
		}else{
			a[1] = y;
		}
		
		return 0;
	}
	
	int init(string x, string y){
		a[0] = x;
		a[1] = y;
		
		return 0;
	}
	
	string echo(int x){
		return a[x];
	}
};

killbox box;

string read(){
	string ans;
	
	cin >> ans;
	
	return ans;
}

int n;

int main(){
	std::ios::sync_with_stdio(false);
	int i, j;
	
	box.init(read(), read());
	
	cin >> n;
	
	cout << box.echo(0) << " " << box.echo(1) << endl;
	
	for(i=1;i<=n;i++){
		box.kill(read(), read());
		cout << box.echo(0) << " " << box.echo(1) << endl;
	}
	
	
	return 0;
}