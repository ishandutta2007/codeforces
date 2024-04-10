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
using namespace std;
set<int> ms;
int n, ai;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    int now = 0;
    for (int i=0;i<2*n;i++){
        cin >> ai;
        if (!ms.count(ai)) {ms.insert(ai); now++;ans = max(ans, now);}
        else {ms.erase(ai);now--;}
    }
    cout << ans << endl;
    return 0;
}