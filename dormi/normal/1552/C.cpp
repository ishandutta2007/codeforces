#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=201;
bool notused[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k,a,b;
        cin>>n>>k;
        for(int i=1;i<=2*n;i++)notused[i]=true;
        vector<pii> pairs;
        for(int i=0;i<k;i++){
            cin>>a>>b;
            notused[a]=false;
            notused[b]=false;
            if(a>b)swap(a,b);
            pairs.push_back({a,b});
        }
        vector<int> ord;
        for(int i=1;i<=2*n;i++){
            if(notused[i])ord.push_back(i);
        }
        for(int i=0;i<sz(ord)/2;i++){
            a=ord[i],b=ord[(i+sz(ord)/2)%sz(ord)];
            if(a>b)swap(a,b);
            pairs.push_back({a,b});

        }
        int am=0;
        sort(pairs.begin(),pairs.end());
        for(int i=0;i<sz(pairs);i++){
            for(int j=i+1;j<sz(pairs);j++){
                int cnt=0;
                if(pairs[j].first>pairs[i].second)cnt++;
                if(pairs[j].second>pairs[i].second)cnt++;
                if(cnt==1)am++;
            }
        }
        printf("%d\n",am);
    }
    return 0;
}