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
int cal(int x,int y,int a,int b){
    return min(x/a,y/b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        int l=0,r=min(x/a,y/b),ans=0;
        if(a==b){
            printf("%d\n",min(x/a,y/b));
            continue;
        }
        while(l<r){
            int rmid=(l+r)/2+1,lmid=(l+rmid)/2;
            //cout<<lmid<<" "<<rmid<<endl;
            int la=lmid+cal(y-lmid*b,x-lmid*a,a,b),ra=rmid+cal(y-rmid*b,x-rmid*a,a,b);
            if(la<ra) l=lmid+1;
            else if(la>ra) r=rmid-1;
            else{
                for(int i=l;i<=r;i++) ans=max(ans,i+cal(y-i*b,x-i*a,a,b));
                break;
            }
            //cout<<lmid<<" "<<rmid<<" "<<l<<" "<<r<<endl;
        }
        cout<<max(ans,l+cal(y-l*b,x-l*a,a,b))<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp