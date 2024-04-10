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
    //cin>>T;
    while(T--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        long long ans=0;
        for(int i=a;i<=b;i++){
            int st,ed;
            if(i+b>d){
                ans+=1LL*(c-b+1)*(d-c+1);
                continue;
            }
            if(b+i<=c) st=1;
            else st=b+i-c;
            if(c+i>d) ed=d-c+1;
            else ed=i;
            ans+=1LL*(st+ed)*(ed-st+1)/2;
            //cout<<st<<" "<<ed<<" "<<ans<<endl;
            if(c+i>d) ans+=1LL*(c-d+i-1)*(d-c+1);
            //cout<<st<<" "<<ed<<" "<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}