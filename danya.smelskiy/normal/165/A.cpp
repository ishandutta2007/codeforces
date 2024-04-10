#include <bits/stdc++.h>
using namespace std;
long long n,ans;
pair<long long,long long> a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
    }
    for (int i=1;i<=n;++i){
        bool up=false,down=false,ll=false,rr=false;
        for (int j=1;j<=n;++j){
            if (a[j].first==a[i].first && a[j].second>a[i].second) up=true;
            else if (a[j].first==a[i].first && a[j].second<a[i].second) down=true;
            else if (a[j].first<a[i].first && a[j].second==a[i].second) ll=true;
            else if (a[j].first>a[i].first && a[j].second==a[i].second) rr=true;
        }
        if (up && down && ll && rr) ++ans;
    }
    cout<<ans;
}