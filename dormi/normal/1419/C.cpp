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
        int n,x;
        cin>>n>>x;
        bool allinfc=true;
        bool doneinfc=false;
        int sum=0;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a!=x){
                allinfc=false;
            }
            else doneinfc=true;
            sum+=(x-a);
        }
        if(allinfc)printf("0\n");
        else if(sum==0||doneinfc)printf("1\n");
        else printf("2\n");
    }
    return 0;
}