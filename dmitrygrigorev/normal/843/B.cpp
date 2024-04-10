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
#include <ctime>
#define int long long
using namespace std;
int32_t main(){
	srand(time(NULL));
	int n, start, x;
	cin >> n >> start >> x;
	int K = 1000;
	set<int> used;
	int max_value = -1000;
	int next;
	for (int i=0; i < min(K, n-1); i++){
		int q;
		while (true){
			int r = ((rand() * rand()) % n) + 1;
			if (!used.count(r)){
				q = r;
				break;
			}
		}
		cout << "? " << q << endl;
		cout.flush();
		int v, nn;
		cin >> v >> nn;
		if (v > max_value && v < x){
            next = nn;
            max_value = v;
		}
	}
	cout << "? " << start << endl;
	cout.flush();
	int v, nn;
	cin >> v >> nn;
	if (v > max_value && v < x){
		next = nn;
	}
	if (v >= x){
        cout << "! " << v << endl;
        cout.flush();
        return 0;
	}
    while (true){
		if (next == -1){
			cout << "! -1" << endl;
			cout.flush();
			return 0;
		}
		cout << "? " << next << endl;
		cout.flush();
		int v, nn;
		cin >> v >> nn;
		if (v >= x){
			cout << "! " << v << endl;
			cout.flush();
			return 0;
		}
		if (nn == -1){
			cout << "! -1" << endl;
			cout.flush();
			return 0;
		}
		next = nn;
    }
	return 0;
}