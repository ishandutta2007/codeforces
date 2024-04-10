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
	string s;
	cin >> s;
	int ans = 10;
	for (int a=0; a < 10; a++){
		for (int b=0; b < 10; b++){
			for (int c=0; c < 10; c++){
				for (int d=0; d < 10; d++){
					for (int e=0; e < 10; e++){
						for (int f=0; f < 10; f++){
							if (a + b + c != d + e + f) continue;
							int ch = 0;
							if (a + '0' != s[0]) ch++;
							if (b + '0' != s[1]) ch++;
							if (c + '0' != s[2]) ch++;
							if (d + '0' != s[3]) ch++;
							if (e + '0' != s[4]) ch++;
							if (f + '0' != s[5]) ch++;
							ans = min(ans, ch);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}