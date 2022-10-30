#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)        cerr<<#a<<": "<<a<<endl;
#else
#define tr(a)    
#endif
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;

void solve(){
    int N,k;
    scanf("%d%d",&N,&k);
    ll x[N+1];
    x[0]=0;
    rep(i,0,N)scanf("%lld",&x[i+1]);
    partial_sum(x,x+N+1,x);
    if(k==1){
        ll ans=0;
        map<ll,int>m;
        for(int i=N;i>=0;i--){
            if(m.find(x[i]+1)!=m.end())
                ans+=m[x[i]+1];
            m[x[i]]++;
        }
        printf("%lld\n",ans);
    }
    else if(k==-1){
        ll ans=0;
        map<ll,int>m;
        for(int i=N;i>=0;i--){
            if(m.find(x[i]+1)!=m.end())
                ans+=m[x[i]+1];
            if(m.find(x[i]-1)!=m.end())
                ans+=m[x[i]-1];
            
            m[x[i]]++;
        }
        printf("%lld\n",ans);
    }
    else{
        ll ans=0;
        map<ll,int>m;
        for(int i=N;i>=0;i--){
            ll cur=1;
            while(true){
                if(abs(cur)>=1e15)break;
                if(m.find(x[i]+cur)!=m.end())
                ans+=m[x[i]+cur];
                cur*=k;
            }
            m[x[i]]++;
        }
        printf("%lld\n",ans);
    }
}

signed main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}