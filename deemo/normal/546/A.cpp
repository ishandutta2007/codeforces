#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

long long k , n , w;

int main(){
    cin >> k >> n >> w;
    long long t = w * (w + 1) / 2;
    long long ans = t * k;
    if (n < ans)    cout << ans - n << endl;    
    else    cout << 0 << endl;
    return 0;
}