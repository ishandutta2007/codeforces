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
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ai;
    cin >> n;
    vector<int> data(n);
    for (int i=0; i < n; i++){
        cin >> data[i];
    }
    int ans = -1;
    for (int zeros=0; zeros<1000; zeros++){
        int number=n, counter=0;
        for (int i=0; i < n; i++){
            if (counter >= zeros){
                number = i;
                break;
            }
            counter += (data[i] == 0);
        }
        for (int i=number; i < n; i++){
            counter += (data[i] == 1);
        }
        ans = max(ans ,counter);
    }
    cout << ans << endl;
    return 0;
}