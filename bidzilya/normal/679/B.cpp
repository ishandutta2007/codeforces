#include <vector>
#include <iostream>
#include <string>

#include <cassert>
using namespace std;

const int MAX_RESULT = 18;

const long long MAX_M = 1e15 + 1;

const int LIM = 4e7;

short result[LIM];
int maxResult[LIM];

void BuildResult() {
    result[0] = 0;
    maxResult[0] = 0;
    int mx = 0;
    for (int i = 1; i < LIM; ++i) {
        while ((mx + 1) * (mx + 1) * (mx + 1) <= i) {
            ++mx;
        }

        result[i] = result[i - mx * mx * mx] + 1;
        maxResult[i] = maxResult[i - 1];

        if (result[i] >= result[maxResult[i]]) {
            maxResult[i] = i;
        }
    }
}

int GetMaxCube(long long x) {
    int bl = 0;
    int br = 1e5;
    int ba = 0;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (1LL * bm * bm * bm < x) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    return ba;
}

const vector<long long> BORDERS = {
    1LL, 2LL, 3LL, 4LL, 5LL, 6LL, 7LL,
    15LL, 23LL, 50LL, 114LL, 330LL, 1330LL,
    10591LL, 215970LL, 19464802LL, 16542386125LL, 
    409477218238718LL, 1000000000000001LL};

const int MAX_CUBE = 1e5 + 1111;

vector<long long> cubes;

void BuildCubes() {
    cubes.resize(MAX_CUBE);
    for (int i = 0; i < MAX_CUBE; ++i) {
        cubes[i] = 1LL * i * i * i;
    }
}

pair<short, long long> GetMaxResult(long long m) {
    if (m <= LIM) {
        return make_pair(result[maxResult[m - 1]], maxResult[m - 1]);
    }
    short glResult = 0;
    for (int i = 1; i < (int) BORDERS.size(); ++i) {
        if (m > BORDERS[i - 1] && m <= BORDERS[i]) {
            glResult = i;
        }
    }
    int maxCube = GetMaxCube(m);
    for (long long i = maxCube; i >= 1; --i) {
        long long m2 = min(cubes[i + 1], m) - cubes[i];

        pair<short, long long> buf = GetMaxResult(m2);

        if (buf.first + 1 == glResult) {
            return make_pair(glResult, cubes[i] + buf.second);
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BuildResult();
    BuildCubes();

    long long m;
    cin >> m;
    ++m;

    const pair<short, long long> result = GetMaxResult(m);

    cout << result.first << " " << result.second << endl;

    return 0;
}