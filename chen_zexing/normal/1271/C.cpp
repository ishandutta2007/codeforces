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
int x[200005],y[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,sx,sy,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        cin>>n>>sx>>sy;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>sx) cnt1++;
            if(x[i]<sx) cnt3++;
            if(y[i]>sy) cnt2++;
            if(y[i]<sy) cnt4++;
        }
        if(cnt1>=cnt2&&cnt1>=cnt3&&cnt1>=cnt4) printf("%d\n%d %d",cnt1,sx+1,sy);
        else if(cnt2>=cnt1&&cnt2>=cnt3&&cnt2>=cnt4) printf("%d\n%d %d",cnt2,sx,sy+1);
        else if(cnt3>=cnt1&&cnt3>=cnt2&&cnt3>=cnt4) printf("%d\n%d %d",cnt3,sx-1,sy);
        else printf("%d\n%d %d",cnt4,sx,sy-1);

    }
    return 0;
}