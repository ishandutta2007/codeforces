#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll am=0;
        ll mi=0;
        ll last=0;
        ll loc=1;
        ll sum=0;
        for(char x:s){
            if(x=='-')am--;
            else am++;
            if(am<last){
                sum+=loc;
                last=am;
            }
            mi=min(mi,am);
            loc++;
        }
        printf("%lli\n",ll(sz(s))+sum);
    }
    return 0;
}