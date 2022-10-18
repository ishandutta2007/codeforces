#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)

int road[4][4];
int sum[4];

class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		for (int i = 0; i < 4; i++) {
			sum[i] = 0;
			for (int j = 0; j < 4; j++) {
				in >> road[i][j];
				if (j != 3) sum[i] += road[i][j];
			}
		}

		int ans = 1;
		for (int i = 0; i < 4; i++) {
			if (road[i][3] && (sum[i] || road[(i + 2) % 4][1] || road[(i + 1) % 4][0] || road[(i + 3) % 4][2])) ans = 0;
		}
		out << (ans ? "NO" : "YES") << endl;
	}
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}