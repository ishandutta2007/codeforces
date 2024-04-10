#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a;
        map<int,int> freq,totfreq;
        int last=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>a;
            totfreq[a]++;
            if(i==0)freq[a]++;
            if(a==last)freq[a]+=2,cnt++;
            last=a;
        }
        freq[last]++;
        int ma=0;
        for(auto x:totfreq)ma=max(ma,x.second);
        if(2*ma-1>n)printf("-1\n");
        else{
            ma=0;
            for(auto x:freq)ma=max(ma,x.second);
            printf("%d\n",cnt+max(0,ma-(cnt+2)));
        }
    }
    return 0;
}