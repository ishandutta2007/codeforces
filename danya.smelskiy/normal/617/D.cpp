#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=3;++i)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+4);
    if ((a[1].first==a[2].first && a[2].first==a[3].first) || (a[1].second==a[2].second && a[2].second==a[3].second)) {
        cout<<"1";
        return 0;
    }
    for (int i=1;i<=3;++i)
        for (int j=i+1;j<=3;++j) if (a[i].first==a[j].first)
            for (int k=1;k<=3;++k)
    if (i!=k && j!=k) {
        int x=a[i].second;
        int y=a[j].second;
        if (x>y) swap(x,y);
        int z=a[k].second;
        if (z<=x || z>=y) {
            cout<<2;
            return 0;
        }
    }
    for (int i=1;i<=3;++i)
        for (int j=i+1;j<=3;++j) if (a[i].second==a[j].second)
            for (int k=1;k<=3;++k)
    if (i!=k && j!=k) {
        int x=a[i].first;
        int y=a[j].first;
        if (x>y) swap(x,y);
        int z=a[k].first;
        if (z<=x || z>=y) {
            cout<<2;
            return 0;
        }
    }
    cout<<3;
}