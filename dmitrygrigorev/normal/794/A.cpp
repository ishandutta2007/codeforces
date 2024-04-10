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
int a, b, c;
int n, ai;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int ans = 0;
    cin >> a >> b >> c;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        if (ai > b && ai < c){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}