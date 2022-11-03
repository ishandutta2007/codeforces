#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n,ans;

int main(){
    ans = 1;
    cin >> n;
    int last = -1;
    int cur_p = 0;
    for (int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        int cur = x*60 + y;
        if (cur==last)
            cur_p++;
        else{
            ans = max(ans,cur_p);
            cur_p=1;
            last = cur;
        }
    }
    ans=max(ans,cur_p);
    cout << ans << endl;
    return 0;
}