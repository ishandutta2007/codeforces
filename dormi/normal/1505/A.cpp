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
    setbuf(stdout,NULL);
    int cnt=0;
    string a;
    while(!cin.eof()){
        cin>>a;
        cnt++;
        if(cnt==3){
            printf("NO\n");
            cnt=0;
        }
    }
    return 0;
}