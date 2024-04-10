#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int n;
string res;
bool work(const string& a, const string& b){
    int zca=0,oca=0,zcb=0,ocb=0;
    for(int i=0;i<2*n;i++){
        if(a[i]=='0')zca++;
        else oca++;
        if(b[i]=='0')zcb++;
        else ocb++;
    }
    if(zca>=n&&zcb>=n){
        vector<pii> azero,bzero;
        azero.push_back({0,0});
        bzero.push_back({0,0});
        for(int i=0;i<2*n;i++){
            if(a[i]=='0'){
                azero.back().second=1;
                azero.push_back({0,0});
            }
            else azero.back().first++;
            if(b[i]=='0'){
                bzero.back().second=1;
                bzero.push_back({0,0});
            }
            else bzero.back().first++;
        }
        int am=0;
        res.resize(3*n);
        for(int i=0;i<max(sz(azero),sz(bzero));i++){
            for(int j=0;j<max((i>=sz(azero)?0:azero[i].first),(i>=sz(bzero)?0:bzero[i].first));j++){
                res[am++]='1';
            }
            if((i<sz(azero)&&azero[i].second>=1)||(i<sz(bzero)&&bzero[i].second>=1))res[am++]='0';
        }
        res.resize(am);
        return true;
    }
    else if(oca>=n&&ocb>=n){
        vector<pii> azero,bzero;
        azero.push_back({0,0});
        bzero.push_back({0,0});
        for(int i=0;i<2*n;i++){
            if(a[i]=='1'){
                azero.back().second=1;
                azero.push_back({0,0});
            }
            else azero.back().first++;
            if(b[i]=='1'){
                bzero.back().second=1;
                bzero.push_back({0,0});
            }
            else bzero.back().first++;
        }
        int am=0;
        res.resize(3*n);
        for(int i=0;i<max(sz(azero),sz(bzero));i++){
            for(int j=0;j<max((i>=sz(azero)?0:azero[i].first),(i>=sz(bzero)?0:bzero[i].first));j++){
                res[am++]='0';
            }
            if((i<sz(azero)&&azero[i].second>=1)||(i<sz(bzero)&&bzero[i].second>=1))res[am++]='1';
        }
        res.resize(am);
        return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        if(work(a,b)){
            cout<<res<<"\n";
        }
        else if(work(a,c)){
            cout<<res<<"\n";
        }
        else{
            assert(work(b,c));
            cout<<res<<"\n";
        }
    }
    return 0;
}