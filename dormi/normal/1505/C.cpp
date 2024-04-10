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
    string a;
    cin>>a;
    for(int i=2;i<sz(a);i++){
        if(a[i]-'A'!=((a[i-1]-'A')+(a[i-2]-'A'))%26){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}