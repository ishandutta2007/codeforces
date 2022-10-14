#include "bits/stdc++.h"
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
        int n;
        cin>>n;
        int a;
        int cnt=0;
        bool last=true;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a!=i&&last)cnt++;
            last = a == i;
        }
        if(cnt<=1)printf("%d\n",cnt);
        else printf("2\n");
    }
    return 0;
}