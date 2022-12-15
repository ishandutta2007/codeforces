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
double ans=0;
void dfs(double a,double b,double c,double v,double p,int step){
    if(p<1e-6) return;
    if(fabs(c-100000)<1e-6){
        ans+=p*step;
        return;
    }
    if(a!=0) {
        if(b!=0) {
            if (a <= v) dfs(0, b + a / 2, c + a / 2, v, p * a/100000, step + 1);
            else dfs(a - v, b + v / 2, c + v / 2, v, p * a/100000, step + 1);
        }
        else{
            if(a<=v) dfs(0,0,100000,v,p*a/100000,step+1);
            else dfs(a-v,0,c+v,v,p*a/100000,step+1);
        }
    }
    if(b!=0) {
        if(a!=0) {
            if (b <= v) dfs(a + b / 2, 0, c + b / 2, v, p * b/100000, step + 1);
            else dfs(a + v / 2, b - v, c + v / 2, v, p * b/100000, step + 1);
        }
        else{
            if(b<=v) dfs(0,0,100000,v,p*b/100000,step+1);
            else dfs(0,b-v,c+v,v,p*b/100000,step+1);
        }
    }
    ans+=p*c/100000*step;
    //cout<<ans<<" "<<step<<endl;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        double a,b,c,v;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&v);
        a*=100000,b*=100000,c*=100000,v*=100000;
        ans=0;
        dfs(a,b,c,v,100000,1);
        printf("%.8lf\n",ans/100000);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//