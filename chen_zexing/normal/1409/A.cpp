#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a,b;
        scanf("%d%d",&a,&b);
        int c=abs(a-b);
        cout<<c/10+((c%10)>0)<<endl;
    }
    return 0;
}