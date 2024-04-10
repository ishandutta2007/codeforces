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
unordered_map<long long ,int> mp;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        int cnt=0;
        for(int i=1,x,y;i<=q;i++){
            scanf("%d%d",&x,&y);
            mp[1LL*x*n+y]^=1;
            if(mp[1LL*x*n+y]){
                cnt+=mp[1LL*(3-x)*n+y-1];
                cnt+=mp[1LL*(3-x)*n+y];
                cnt+=mp[1LL*(3-x)*n+y+1];
            }
            else{
                cnt-=mp[1LL*(3-x)*n+y-1];
                cnt-=mp[1LL*(3-x)*n+y];
                cnt-=mp[1LL*(3-x)*n+y+1];
            }
            //cout<<cnt<<endl;
            if(cnt==0) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}