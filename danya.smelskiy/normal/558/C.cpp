#include <bits/stdc++.h>
using namespace std;

int n;
int llast[100005],ans[100005],kol[100005];
int a[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        int last=0;
        while (a[i]) {
            ++kol[a[i]];
            ans[a[i]]+=last;
            llast[a[i]]=i;
            int ll=a[i]+a[i];
            int rr=1;
            while (ll<=1e5) {
                if (llast[ll]==i) break;
                llast[ll]=i;
                kol[ll]++;
                ans[ll]+=last+rr;
                ++rr;
                ll+=ll;
            }
            ++last;
            a[i]/=2;
        }
    }
    int res=1e9;
    for (int i=1;i<=1e5;++i)
        if (kol[i]==n) res=min(res,ans[i]);
    cout<<res;
}