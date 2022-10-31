#include <bits/stdc++.h>
using namespace std;




int n;
int a[100];


int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    vector<int> v;
    for (int i=1;i<=n;++i) {
        bool t=false;
        for (int j=i+1;j<=n;++j)
            if (a[j]==a[i]) t=true;
        if(!t)  {
            v.push_back(a[i]);
        }
    }
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}