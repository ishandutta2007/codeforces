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
        double d=3.14159265/n;
        for(int i=1;i<=n;i++) ans+=sin(d*i);
        printf("%.8lf\n",ans);
    }
    return 0;
}