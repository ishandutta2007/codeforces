#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
set <long long> s,mul;
map <long long,set<long long>> mp;
map <long long,int> cnt;
map <long long,long long> cur;
int limit=450;
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int q;
        scanf("%d",&q);
        s.insert(0);
        for(int i=1;i<=q;i++){
            char c=';';
            long long x;
            while(c!='+'&&c!='-'&&c!='?') scanf("%c",&c);
            scanf("%lld",&x);
            if(c=='+') s.insert(x);
            else if(c=='-'){
                for(auto t:mul)
                    if(x%t==0&&x<cur[t])
                        mp[t].insert(x);
                s.erase(x);
            }
            else{
                if(mul.find(x)==mul.end()){
                    mp[x].clear(),mp[x].insert(x),cur[x]=x;
                }
                while(1){
                    if(s.find(*mp[x].begin())==s.end()){
                        printf("%lld\n",*mp[x].begin());
                        break;
                    }
                    if(mp[x].size()>1) mp[x].erase(mp[x].begin());
                    else{
                        long long temp=*mp[x].begin();
                        mp[x].erase(mp[x].begin());
                        mp[x].insert(temp+x),cnt[x]++,cur[x]=temp+x;
                        if(cnt[x]>=limit) mul.insert(x);
                    }
                }
            }
        }
    }
    return 0;
}