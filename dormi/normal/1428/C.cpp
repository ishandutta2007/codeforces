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
        string a;
        cin>>a;
        int ama=0;
        int bleft=0;
        int len=sz(a);
        for(auto x:a){
            if(x=='A')ama++;
            else{
                if(ama>0){
                    ama--;
                    len-=2;
                }
                else bleft++;
            }
        }
        if(bleft%2==0)len-=bleft;
        else len-=(bleft-1);
        printf("%d\n",len);
    }
    return 0;
}