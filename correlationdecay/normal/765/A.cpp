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
string home;
int main(){
	int n;
	cin >> n;
	if(n & 1)
		puts("contest");
	else
		puts("home");
	return 0;
}