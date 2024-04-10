#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5, inf = 111111111;

struct state {
    int z, n;
};

bool res(state a, state b) {
    return a.z > b.n && a.n > b.z;
}

state q[4];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 4; ++i) {
        cin >> q[i].z >> q[i].n;
    }
    int sum = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (i != j) {
                state team1;
                team1.z = q[i].z;
                team1.n = q[j].n;
                int f = 0, f2 = 0;
                for (int e = 2; e < 4; ++e) {
                    for (int r = 2; r < 4; ++r) {
                        if (e != r) {
                            state team2;
                            team2.z = q[e].z;
                            team2.n = q[r].n;
                            if (res(team1, team2)) {
                                ++f;
                            }
                            if (res(team2, team1)) {
                                f2 = 1;
                            }
                        }
                    }
                }
                //cout << i << ' ' << j << "   " << f2 << endl;
                sum += f2;
                if (f == 2) {
                    cout << "Team 1" << endl;
                    return 0;
                }
            }
        }
    }
    if (sum == 2) {
        cout << "Team 2" << endl;
        return 0;
    }
    cout << "Draw" << endl;
    return 0;
}