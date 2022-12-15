#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;

int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int s,now=1,tot=0,cnt=0;
        cin>>s;
        while(tot<s) tot+=now,now+=2,cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}