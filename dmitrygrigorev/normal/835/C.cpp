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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, c, xi, yi, si, ti, x2i, y2i;
    cin >> n >> q >> c;
    c++;
    int prefix[c][100][101];
    vector<vector<pair<int, int> > > stars;
    for (int i=0; i < 100; i++){
        vector<pair<int, int> > v;
        stars.push_back(v);
    }
    for (int i=0; i < n; i++){
        cin >> xi >> yi >> si;
        stars[xi-1].push_back(make_pair(yi-1, si));
    }
    for (int i=0; i < 100; i++){
        sort(stars[i].begin(), stars[i].end());
    }
    for (int i=0; i < c; i++){
        for (int j=0; j < 100; j++){
            prefix[i][j][0] = 0;
            int u = 1;
            int summ = 0;
            int k = 0;
            while (u <= 100){
                if (k >= stars[j].size() || stars[j][k].first > u-1){
                    prefix[i][j][u] = summ;
                    u++;
                }
                else{
                    summ += (stars[j][k].second + i) % c;
                    k++;
                }
            }
        }
    }
    for (int i=0; i < q; i++){
        cin >> ti >> xi >> yi >> x2i >> y2i;
        int ans = 0;
        ti %= c;
        for (int j=xi-1; j < x2i; j++){
            ans += prefix[ti][j][y2i] - prefix[ti][j][yi - 1];
        }
        cout << ans << endl;
    }
    return 0;
}