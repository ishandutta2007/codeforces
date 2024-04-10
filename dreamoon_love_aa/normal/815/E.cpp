#include <bits/stdc++.h>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL f(LL N,LL K){
    if(K==1)return N/2;
    K--;
    map<LL,LL>q[2];
    q[0][N/2]=1;
    q[1][N-N/2]=1;
    LL use[2]={};
    while(1){
        pair<LL,LL> v[2]={*q[0].rbegin(),*q[1].rbegin()};
        int id=(v[0].F/2<v[1].F/2);
        if(v[id].S>=K)return f(N/2+(N%2)*id,K+use[id])+id*(N/2);
        use[id]+=v[id].S;
        K-=v[id].S;
        q[id].erase(v[id].F);
        q[id][v[id].F/2]+=v[id].S;
        q[id][v[id].F-v[id].F/2]+=v[id].S;
    }
}
int main(){
    LL N,K;
    cin>>N>>K;
    if(K==1)cout<<1;
    else if(K==2)cout<<N;
    else{
        cout<<1+f(N-1,K-2)<<endl;
    }
    return 0;
}