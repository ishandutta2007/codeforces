#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
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
#define li __int128_t
#define ull unsigned long long
using namespace std;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int a,b,c;
        cin>>a>>b>>c;
        int mn=min(min(a/3,b/2),c/2),ans=mn*7,cc=0;
        a-=mn*3,b-=mn*2,c-=mn*2;
        int seq[7]={0,1,2,0,2,1,0},rest[3];
        rest[0]=a,rest[1]=b,rest[2]=c;
        for(int i=0;i<7;i++){
            int temp[3],cnt=0;
            for(int j=0;j<3;j++) temp[j]=rest[j];
            for(int j=i;1;j=(j+1)%7){\
                if(temp[seq[j]]) temp[seq[j]]--,cnt++;
                else break;
            }
            cc=max(cc,cnt);
        }
        printf("%d\n",ans+cc);
    }
    return 0;
}
//
/// 
//01
//