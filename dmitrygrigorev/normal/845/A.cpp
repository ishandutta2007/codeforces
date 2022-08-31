#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int32_t main(){
	int n, ai;
	vector<int> data;
	cin >> n;
	for (int i=0; i < 2*n; i++){
		cin >> ai;
		data.push_back(ai);
	}
	sort(data.begin(), data.end());
	if (data[n-1] != data[n]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}