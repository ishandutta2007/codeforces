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
#include <deque>
#define int long long
using namespace std;
vector<vector<int> > data;
vector<int> comps;
vector<bool> cycl, oso;
vector<int> nums;
int n, ans, counter;
int K = 1000000007;
int dfs(int vertex){
    if (nums[vertex] != -1){
        if (nums[vertex] == counter){
            if (data[vertex].size() > 0 && data[vertex][0] == vertex){
                oso.push_back(true);
            }
            else oso.push_back(false);
            comps.push_back(0);
            cycl.push_back(true);
            return counter;
        }
        return nums[vertex];
    }
    nums[vertex] = counter;
    if (data[vertex].size() == 0){
        comps.push_back(1);
        oso.push_back(false);
        cycl.push_back(false);
        return counter;
    }
    int v = data[vertex][0];
    int r = dfs(v);
    comps[r]++;
    nums[vertex] = r;
    return r;
}
int32_t main(){
    cin >> n;
    for (int i=0; i < 2*n; i++){
        vector<int> help;
        data.push_back(help);
        nums.push_back(-1);
    }
    counter = 0;
    ans = 1;
    int ai, bi;
    for (int i=0; i < n; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
    }
    for (int i=0; i < 2*n; i++){
        if (nums[i] == -1){
            dfs(i);
            if (comps.size() == counter+1){
                counter++;
            }
        }
    }
    for (int i=0; i < comps.size(); i++){
        if (cycl[i]){
            if (!oso[i]){
            ans *= 2;
            ans %= K;
            }
        }
        else{
            ans *= comps[i];
            ans %= K;
        }
    }
    cout << ans << endl;
    return 0;
}