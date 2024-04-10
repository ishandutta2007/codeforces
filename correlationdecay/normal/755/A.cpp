#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
bool check(int x){
	for(int i = 2; i * i <=x ;i ++){
		if(x % i ==0)
			return 1;
	}
	return 0;
}
int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= 1000;i++){
		if(check(i * n + 1)){
			cout << i << endl;
			return 0;
		}
	}
}