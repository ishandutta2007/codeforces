#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int r,c,ans=0,rc,r_c;
        cin>>r>>c;
        printf("SCAN %d %d\n",1,1);
        fflush(stdout);
        scanf("%d",&ans),rc=ans+4;
        printf("SCAN %d %d\n",1,c);
        fflush(stdout);
        scanf("%d",&ans),r_c=ans-c*2+2;
        int rr=(rc+r_c)/2,cc=rc-rr;
        printf("SCAN %d %d\n",rr/2,1);
        fflush(stdout);
        scanf("%d",&ans);
        int rd=ans-(cc-2);
        printf("SCAN %d %d\n",1,cc/2);
        fflush(stdout);
        scanf("%d",&ans);
        int cd=ans-(rr-2);
        int r1=(rr-rd)/2,r2=rr-r1,c1=(cc-cd)/2,c2=cc-c1;
        printf("DIG %d %d\n",r1,c1);
        fflush(stdout);
        scanf("%d",&ans);
        if(ans){
            printf("DIG %d %d\n",r2,c2);
            fflush(stdout);
            scanf("%d",&ans);
        }
        else{
            printf("DIG %d %d\n",r1,c2);
            fflush(stdout);
            scanf("%d",&ans);
            printf("DIG %d %d\n",r2,c1);
            fflush(stdout);
            scanf("%d",&ans);
        }
    }
    return 0;
}
//unordered_map