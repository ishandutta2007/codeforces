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
        int a,b,c,d,x,y,x1,y1,x2,y2;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
        if(x+b-a>=x1&&x+b-a<=x2&&y+d-c>=y1&&y+d-c<=y2&&((a==0&&b==0)||x1!=x2)&&((c==0&&d==0)||y1!=y2)) puts("Yes");
        else puts("No");
    }
    return 0;
}