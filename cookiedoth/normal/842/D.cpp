#include <iostream>

using namespace std;

const int lg = 20;
const int mx = (1 << lg);

int br[4*mx];

void add(int num) {
	int pos = 0;
	for (int i = lg - 1; i >= 0; --i) {
		br[pos]++;
		if ((num >> i) & 1)
			pos = pos * 2 + 2;
		else
			pos = pos * 2 + 1;
	}
	br[pos]++;
}

int ans_query(int val) {
    int pos = 0, kek = 0;
    for (int i = lg - 1; i >= 0; --i) {
        if ((val >> i) & 1) {
            if (br[2*pos+2] > 0) {
                pos = pos * 2 + 2;
                kek += (1 << i);
            }
            else
                pos = pos * 2 + 1;
        }
        else {
            if (br[2*pos+1] > 0)
                pos = pos * 2 + 1;
            else {
                pos = pos * 2 + 2;
                kek += (1 << i);
            }
        }
    }
    return kek ^ val;
}

int current, n, m;
bool exist[mx];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        exist[temp] = 1;
    }
    for (int i = 0; i < mx; ++i) {
        if (!exist[i])
            add(i);
    }
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        current ^= temp;
        cout << ans_query(current) << endl;
    }
}