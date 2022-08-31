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
	vector<pair<int, int> > ev;
	int n, ai, bi;
	cin >> n;
	for (int i=0; i < n; i++){
		cin >> ai >> bi;
		ev.push_back(make_pair(bi, 1));
		ev.push_back(make_pair(ai, 0));
	}
	sort(ev.begin(), ev.end());
	int op = 0;
	int ma = 0;
	for (int i=0; i < 2*n;i++){
		if (ev[i].second == 1) op--;
		else op++;
		ma = max(ma, op);
	}
	if (ma <= 2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}