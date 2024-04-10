#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<lli,pll> times;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        lli m;
        cin>>n>>m;
        times.clear();
        lli t,l,h;
        for(int i=0;i<n;i++){
            cin>>t>>l>>h;
            if(!times.count(t)){
                times[t]={-1e9,1e9};
            }
            times[t].first=max(l,times[t].first);
            times[t].second=min(h,times[t].second);
        }
        lli lasttime=0;
        lli templ=m,temph=m;
        bool work=true;
        for(auto x:times){
            templ=templ-(x.first-lasttime);
            temph=temph+(x.first-lasttime);
            templ=max(templ,x.second.first);
            temph=min(temph,x.second.second);
            lasttime=x.first;
            if(templ>temph){
                printf("NO\n");
                work=false;
                break;
            }
        }
        if(work){
            printf("YES\n");
        }
    }
    return 0;
}