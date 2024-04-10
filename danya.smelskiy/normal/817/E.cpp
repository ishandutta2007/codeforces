#include <bits/stdc++.h>
using namespace std;

long long n,x;
map<pair<int,int>,int> kol;
int y;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x==1) {
            int res=0;
            cin>>y;
            for (int j=27;j>=0;--j) {
                if (y&(1<<j)) res|=(1<<(j));
                ++kol[make_pair(j,res)];
            }
        } else if (x==2) {
            cin>>y;
            int res=0;
            for (int j=27;j>=0;--j){
                if (y&(1<<j)) res|=(1<<(j));
                --kol[make_pair(j,res)];
            }
        } else {
            cin>>x>>y;
            int z=x^y;
            int res=0;
            int ans=0;
            for (int j=27;j>=0;--j) {
                if (y&(1<<j)) {
                    int res2=res;
                    res2^=(1<<j)&(x);
                    ans+=kol[make_pair(j,res2)];
                }
                res^=z&(1<<j);
            }
            cout<<ans<<'\n';
        }
    }
}