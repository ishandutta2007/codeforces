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
        string s;
        cin>>s;
        string a=s;
        sort(a.begin(),a.end());
        int cnt=0;
        for(int i=0;i<sz(s);i++)if(a[i]!=s[i])cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}