#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli x,y;
        cin>>x>>y;
        lli a,b;
        cin>>a>>b;
        printf("%lli\n",min(x,y)*min(b,a*2)+abs(x-y)*a);
    }
    return 0;
}