#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;
#define MAX_INT (int)10e9
#define MAX_INT64 (__int64)10e18
#define eps 1e-8

#define open_ins() ifstream cin("input.txt")
#define open_outs() ofstream cout("output.txt");
#define open_outf() freopen("output.txt","w",stdout)
#define open_inf() freopen("input.txt","r",stdin)

const double pi = 3.141592653589793;

int main(){
    int n, a[111];
    double ans = 0;
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    a[0]=0;
    sort(a, a+n+1);
    int cl=1,y=n;
    for (int y=n;y>=1;y--){
        if (cl==1)
            ans += pi*(a[y]*a[y]-a[y-1]*a[y-1]);
        cl = (cl+1)%2;
    }
    cout << ans;
	return 0;
}