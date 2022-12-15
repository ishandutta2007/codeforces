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
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        if(a>b) swap(a,b);
        if(c+r<=a) printf("%d\n",b-a);
        else if(c-r>=b) printf("%d\n",b-a);
        else if(c+r>=b&&c-r<=a) printf("0\n");
        else if(c+r<=b&&c-r>=a) printf("%d\n",b-a-2*r);
        else if(c+r<=b&&c-r<=a) printf("%d\n",b-(c+r));
        else if(c+r>=b&&c-r>=a) printf("%d\n",(c-r)-a);
    }
    return 0;
}