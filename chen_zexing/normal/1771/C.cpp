#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int check(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
int main(){
    for(int i=2;i*i<=1000000000;i++) if(check(i)) v.push_back(i);
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,f=0;
        scanf("%d",&n);
        map <int,int> mp;
        for(int i=1,x;i<=n;i++) {
            scanf("%d",&x);
            for (auto t:v) {
                if (t * t > x) break;
                if(x%t==0){
                    mp[t]++;
                    if(mp[t]>1) f=1;
                    while(x%t==0) x/=t;
                }
            }
            if(x>1){
                mp[x]++;
                if(mp[x]>1) f=1;
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}