#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
int x,y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int kol=0;
    for (int i=1;kol<=n;++i) {
        int z=i;
        while (z%2==0) {
            ++x;
            z/=2;
        }
        while (z%5==0) {
            ++y;
            z/=5;
        }
        z=min(x,y);
        x-=z;
        y-=z;
        kol+=z;
        if (kol==n) ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}