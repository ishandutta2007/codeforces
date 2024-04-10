#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int check(int x){
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    for(int i=2;i*i<=10000000;i++) if(check(i)) v.push_back(i);
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int x,y;
        scanf("%d%d",&x,&y);
        int d=y-x;
        if(d==1){
            puts("-1");
            continue;
        }
        if(gcd(x,y)!=1){
            puts("0");
            continue;
        }
        int ans=INT_MAX;
        for(auto t:v){
            if(t*t>d) break;
            if(d%t==0){
                ans=min(ans,t-x%t);
                while(d%t==0) d/=t;
            }
        }
        if(d>1) ans=min(ans,d-x%d);
        printf("%d\n",ans);
    }
    return 0;
}