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
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ai;
	vector<int> data;
	vector<bool> used;
	vector<int> numbers;
	cin >> n;
	for (int i=0; i < n; i++){
		cin >> ai;
		data.push_back(ai);
		used.push_back(false);
		numbers.push_back(ai);
	}
	sort(numbers.begin(), numbers.end());
	map<int, int> when;
	for (int i=0; i < n; i++){
		when[numbers[i]] = i;
	}
	vector<vector<int> > ans;
	for (int i=0; i < n; i++){
        if (used[i]) continue;
        set<int> ms;
        ms.insert(i);
        ms.insert(when[data[i]]);
        int last = when[data[i]];
        vector<int> vz;
        vz.push_back(i);
        int counter = 1;
        while (ms.size() > counter){
            ms.insert(when[data[last]]);
            vz.push_back(last);
            last = when[data[last]];
            counter++;
        }
        for (int j=0; j < vz.size(); j++){
			used[vz[j]] = true;
        }
        ans.push_back(vz);
	}
	cout << ans.size() << endl;
	for (int i=0; i < ans.size(); i++){
		cout << ans[i].size() << " ";
		sort(ans[i].begin(), ans[i].end());
		for (int j=0; j < ans[i].size(); j++){
			cout << ans[i][j]+1 << " ";
		}
		cout << endl;
	}
	return 0;
}