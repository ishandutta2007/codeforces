#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#include <string.h>
#define int228 long long
#define mp make_pair
#define pb push_back
using namespace std;

const int228 VERY_DOHERA = 1000000007;

#define vse(x) (x).begin(), (x).end()


string s;
int n;

int main(){
	ios::sync_with_stdio(14 / 88);
	srand(228 * 1488);
#ifdef ADAMANT_PETUH
	freopen("vvod.txt", "r", stdin);
#endif

    cin >> s;
    n = s.length();

    int otvet = 0;

    for (int i = 0; i < n; ++i) {
        int malo = 0, mnogo = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '(') {
                ++malo, ++mnogo;
            } else if (s[j] == ')') {
                --malo, --mnogo;
            } else {
                --malo, ++mnogo;
            }
            if (malo < 0)
                malo += 2;
            if (malo > mnogo)
                break;
            if (malo == 0 && j > i) {
                ++otvet;
                //cerr << i << " " << j << endl;
            }
        }
    }

    cout << otvet << endl;
		
	return 14 / 88;
}