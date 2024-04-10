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
    int a,b,c;
    int n;
    cin>>a>>b>>c>>n;
    lli ans=0;
    lli in;
    for(int i=1;i<=n;i++){
        cin>>in;
        if(in>b&&in<c)ans++;
    }
    printf("%lli\n",ans);
    return 0;
}