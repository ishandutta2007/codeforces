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
#include <unordered_set>
#define hash hassh
using namespace std;

int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2||y1==y2){
            printf("%d\n",abs(x1-x2)+abs(y1-y2));
        }
        else printf("%d\n",abs(x1-x2)+abs(y1-y2)+2);
    }
    return 0;
}