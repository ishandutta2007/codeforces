#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<lli> cnt;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        lli x;
        cin>>n>>x;
        lli mi=LLONG_MAX;
        lli a;
        cnt.clear();
        for(int i=0;i<n;i++){
            cin>>a;
            cnt.insert(a);
        }
        for(int b:cnt){
            mi=min(mi,max((lli)2,(x+b-1)/b));
            if(x%b==0)mi=min(mi,x/b);
        }
        printf("%lli\n",mi);
    }
    return 0;
}