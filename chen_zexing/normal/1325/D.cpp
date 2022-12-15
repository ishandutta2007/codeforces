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
        long long u,v;
        cin>>u>>v;
        if(u>v||(u+v)%2){
            puts("-1");
            continue;
        }
        else if(u==0&&v==0){
            puts("0");
        }
        else if(u==v){
            puts("1");
            printf("%lld\n",u);
        }
        else if(((u+(v-u)/2)^((v-u)/2))==u) printf("2\n%lld %lld\n",u+(v-u)/2,(v-u)/2);
        else printf("3\n %lld %lld %lld\n",u,(v-u)/2,(v-u)/2);
        //cout<<((u+(v-u)/2)^((v-u)/2))<<endl;
    }
    return 0;
}