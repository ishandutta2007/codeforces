#include <bits/stdc++.h>
using namespace std;

long double n,m;
pair<string,int> a[1005],b[1005];

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+(int)n+1);
    for (int i=1;i<=n;++i)
    if (i==n || a[i].first!=a[i+1].first) {
        ++m;
        b[(int)m]=a[i];
    }
    cout<<(int)m<<'\n';
    for (int i=1;i<=m;++i) {
        long double kol1=0,kol2=0;
        for (int j=1;j<=m;++j) {
            if (b[j].second<=b[i].second) ++kol1;
            else ++kol2;
        }
        long double z=(kol1/m)*100; //<
        long double zz=(kol2/m)*100; //>
        if (zz>50) cout<<b[i].first<<" noob";
        else if (z>=50 && zz>20) cout<<b[i].first<<" random";
        else if (z>=80 && zz>10) cout<<b[i].first<<" average";
        else if (z>=90 && zz>1) cout<<b[i].first<<" hardcore";
        else if (z>=99) cout<<b[i].first<<" "<<"pro";
        cout<<'\n';
    }
}