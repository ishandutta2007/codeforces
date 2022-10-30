#include <bits/stdc++.h>
using namespace std;
long long ans=1e9;
int n;
long long sum,last;
int lastkol;
pair<int,int> a[100005];

int kol[205];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first;
    for (int i=1;i<=n;++i){
        cin>>a[i].second;
        sum+=a[i].second;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        sum-=a[i].second;
        last+=a[i].second;
        ++lastkol;
        if (a[i].first==a[i+1].first) {
            continue;
        }
        if (lastkol==1) {
            ans=min(ans,sum+last-a[i].second);
            ++kol[a[i].second];
            lastkol=0;
            continue;
        }
        lastkol=i-lastkol-lastkol+1;
        if (lastkol<=0) {
            ans=min(ans,sum);
        } else {
            long long newkol=0;
            long long tr=0;
            for (int j=1;j<=200;++j) {
                newkol+=kol[j];
                tr+=kol[j]*j;
                if (newkol>=lastkol) {
                    tr-=(newkol-(lastkol))*j;
                    ans=min(ans,tr+sum);
                    break;
                }
            }
        }
        lastkol=0;
        for (int j=i;j>0;--j){
                if (a[j].first!=a[i].first) break;
                kol[a[j].second]++;
        }
    }
    cout<<ans;
}