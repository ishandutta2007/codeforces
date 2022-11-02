#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#define maxn 100009
using namespace std;
char s[maxn];
int cur = 0;
int main(){
	long long k, a, b;
	cin >> k >> a >> b;
	if(a < b)
		swap(a, b);
	if(a < k){
		puts("-1");
		return 0;
	}
	if(b < k){
		if(a % k == 0){
			cout << a / k << endl;
		}
		else{
			puts("-1");
		}
		return 0;
	}
	else{
		cout << a / k + b / k << endl;
	}
	return 0;
}