#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxint 1111111111
#define eps 1e-9
int n,k,ans = maxint;

bool may(int x){
    int tmp, sum = 0;
    double res = (double)x;
    while (1){
        tmp = (int)res;
        if (tmp==0)
            break;
        sum = sum + tmp;
        if (sum>=n)
            break;
        res = res/k;
    }
    if (sum>=n)
        return 1;
    else
        return 0;
}

void Binary(){
    int l = 1, r =n;
    while (l<=r){
        int m = (l+r)/2;
        if (may(m)){
            ans = min(ans,m);
            r = m-1;
        }else
            l = m+1;
    }
}

int main(){
    ans = maxint;
    cin >> n >> k;
    Binary();
    cout << ans << endl;
	return 0;
}