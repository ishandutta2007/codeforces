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
#define int long long
using namespace std;
int n, m, ai, bi;
vector<int> one, two, three;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ai >> bi;
        if (ai == 3) three.push_back(bi);
        else if (ai == 2) two.push_back(bi);
        else one.push_back(bi);
    }
    sort(one.begin(), one.end(), greater<int>());
    sort(two.begin(), two.end(), greater<int>());
    sort(three.begin(), three.end(), greater<int>());
    vector<vector<int> > answer;
    for (int i=0;i<=m;i++){
        vector<int> help;
        help.push_back(-100000000000000000);
        help.push_back(-1);
        help.push_back(-1);
        answer.push_back(help);
    }
    answer[0][0] = 0;
    answer[0][1] = 0;
    answer[0][2] = 0;
    for (int i=0;i<=m;i++){
        if (answer[i][1] == -1) continue;
        if (answer[i][1] < one.size()){
            int v = answer[i][0] + one[answer[i][1]];
            if (i + 1 <= m && answer[i+1][0] < v){
                answer[i+1][0] = v;
                answer[i+1][1] = answer[i][1] + 1;
                answer[i+1][2] = answer[i][2];
            }
        }
        if (answer[i][2] < two.size()){
            int v = answer[i][0] + two[answer[i][2]];
            if (i + 2 <= m && answer[i+2][0] < v){
                answer[i+2][0] = v;
                answer[i+2][1] = answer[i][1];
                answer[i+2][2] = answer[i][2] + 1;
            }
        }
    }
    int ans = 0;
    int summ = 0;
    int maximum = 0;
    for (int i=0;i<=m;i++){
        maximum = max(maximum, answer[i][0]);
        answer[i][0] = maximum;
    }
    for (int i=0;i<=three.size();i++){
        if (3 * i > m) break;
        if (i > 0) summ += three[i-1];
        if (summ + answer[m - 3*i][0] > ans){
            ans = summ + answer[m - 3*i][0];
        }
    }
    cout << ans << endl;
    return 0;
}