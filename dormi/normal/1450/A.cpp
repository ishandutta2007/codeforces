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
        string a;
        cin>>a;
        vector<char> st,en;
        for(auto x:a){
            if(x=='b'){
                st.push_back(x);
            }
            else en.push_back(x);
        }
        for(auto x:st)printf("%c",x);
        for(auto x:en)printf("%c",x);
        printf("\n");
    }
    return 0;
}