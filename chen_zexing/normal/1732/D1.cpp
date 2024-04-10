#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
map <long long,long long> mp;
set <long long> s;
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int q;
        cin>>q;
        s.insert(0);
        for(int i=1;i<=q;i++){
            char c='-';
            long long x;
            while(c!='+'&&c!='?') scanf("%c",&c);
            scanf("%lld",&x);
            if(c=='+') s.insert(x);
            else{
                while(s.find(mp[x])!=s.end()) mp[x]+=x;
                printf("%lld\n",mp[x]);
            }
        }
    }
    return 0;
}