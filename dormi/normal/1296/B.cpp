#include<bits/stdc++.h>
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
        lli s;
        cin>>s;
        lli ans=0;
        while(s>=10) {
            ans += (s / 10) * 10;
            s = s % 10 + s / 10;
        }
        printf("%lli\n",ans+s);
    }
    return 0;
}