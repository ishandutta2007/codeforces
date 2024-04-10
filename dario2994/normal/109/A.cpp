#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector <int> res;
	while(n%7!=0){
		n-=4;
		res.push_back(4);
	}
	if(n<0){
		cout << -1;
		return 0;
	}
	while(n>0){
		res.push_back(7);
		n-=7;
	}
	for(int i=0;i<int(res.size());i++)cout << res[i];
}