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
int f[300005];
vector <int> p;
int main() {
    for(int i=2;i<=300000;i++){
        if(!f[i]){
            p.push_back(i);
            for(int j=i*2;j<=300000;j+=i) f[j]=1;
        }
    }
    int T=1;
    cin>>T;
    while(T--){
        int d;
        cin>>d;
        long long ans=1;
        int r=2,x=0,lst=1;
        while(r){
            if(p[x]-lst>=d) ans*=p[x],r--,lst=p[x];
            x++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}