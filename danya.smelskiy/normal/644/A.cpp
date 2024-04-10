#include <bits/stdc++.h>
using namespace std;

long long n,m,k;
bool t;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>n>>m;
    if (n*m<k) {
        cout<<"-1";
        return 0;
    }
    if (m%2==0) t=true;
    for (int i=1;i<=n;++i) {
        if (t==false || (t==true && i%2==1)) {
            for (int j=1;j<=m;++j) {
                if (k) { cout<<k<<" "; --k;}
                else cout<<"0 ";
            }
        } else {
            v.clear();
            for (int j=m;j>0;--j){
                if (k) { v.push_back(k); --k; } else v.push_back(0);
            }
            for (int j=v.size()-1;j>=0;--j) cout<<v[j]<<" ";
        }
        cout<<'\n';
    }
}