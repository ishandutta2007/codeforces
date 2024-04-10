#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1e6+10;
#define LL long long
#define F first
#define S second
void maa(LL& x,LL v){x=max(x,v);}
LL mod,x,an;
int main(){
    int n;
    scanf("%d",&n);
    map<LL,LL>now;
    scanf("%lld",&mod);
    now[mod-1]=0;
    for(int i=1;i<n;i++){
        scanf("%lld",&x);
        if(x>=mod)continue;
        mod=x;
        auto it=now.lower_bound(x);
        vector<pair<LL,LL>> d(it,now.end());
        now.erase(it,now.end());
        for(int j=0;j<d.size();j++){
            maa(now[x-1],d[j].S+(d[j].F-(x-1))/x*x*i);
            maa(now[d[j].F%x],d[j].S+d[j].F/x*x*i);
        }
    }
    for(auto& v: now)maa(an,v.S+n*v.F);
    cout<<an<<endl;
    return 0;
}