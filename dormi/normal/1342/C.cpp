#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli am[200*200+1];
lli mdc;
lli query(lli loc){
    return am[loc%mdc]+am[mdc-1]*(loc/mdc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int q;
        lli a,b;
        cin>>a>>b>>q;
        mdc=a*b;
        for(lli i=1;i<a*b;i++){
            am[i]=am[i-1];
            if((i%a)%b!=(i%b)%a)am[i]++;
        }
        lli l,r;
        while(q--){
            cin>>l>>r;
            printf("%lli ",query(r)-query(l-1));
        }
        printf("\n");
    }
    return 0;
}