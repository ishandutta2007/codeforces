#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        double ans=0;
        double d=3.1415926535897932/n;
        double r=0.5/sin(d/2);
        for(int i=1;i<=(n-1)/2;i++) ans=max(ans,r*cos(3.1415926535897932/4-d*i)*2);
        printf("%.8lf\n",ans);
    }
    return 0;
}