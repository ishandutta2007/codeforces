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
#define int long long
using namespace std;
vector<int> a, b;
bool cmp(int f, int s){
	if (b[f] > b[s]) return true;
	return false;
}
int32_t main(){
	int m, ai;
	cin >> m;
	for (int i=0; i < m; i++){
		cin >> ai;
		a.push_back(ai);
	}
	for (int i=0; i < m; i++){
		cin >> ai;
		b.push_back(ai);
	}
	vector<int> c;
	for (int i=0; i < m; i++){
		c.push_back(i);
	}
	sort(c.begin(), c.end(), cmp);
	sort(a.begin(), a.end());
	vector<int> ans;
	for (int i=0; i < m; i++){
		ans.push_back(0);
	}
	for (int i=0; i < m; i++){
		ans[c[i]] = a[i];
	}
	for (int i=0; i < m; i++){
		cout << ans[i] << " ";
	}
    return 0;
}