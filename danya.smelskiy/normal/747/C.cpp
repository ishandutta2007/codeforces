#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,z;
int t[10005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        int kol=0;
        int sum=0;
        for (int j=1;j<=n;++j) {
            if (t[j]<x) {
                ++kol;
                sum+=j;
                if (kol==y) break;
            }
        }
        if (kol==y) cout<<sum<<'\n';
        else {
            cout<<"-1"<<'\n';
            continue;
        }
        for (int j=1;j<=n;++j) {
            if (t[j]<x)  {
                --kol;
                t[j]=x+z-1;
                if (!kol) break;
            }
        }
    }
}