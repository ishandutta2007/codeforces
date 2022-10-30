#include <bits/stdc++.h>
using namespace std;


long long n,m,x,y;
vector<long long > v;
long long q;
long long ans;
long long kol[100000];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<=(1<<14);++i){
        x=i;
        q=0;
        while (x) {
            q+=x%2;
            x/=2;
        }
        if (q==m) v.push_back(i);
    }
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x>1e4) {
            cout<<"-1";
            return 0;
        }
        for (int j=0;j<v.size();++j) {
            y=v[j]^x;
            ans+=kol[y];
        }
        ++kol[x];
    }
    cout<<ans;
}