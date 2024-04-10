#include <bits/stdc++.h>
using namespace std;


int n;
int s;
int a[1005],b[1005],ans[1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=1;i<=n;++i) {
        cin>>a[i]>>b[i];
        s-=a[i];
        ans[i]=a[i];
    }
    if (s<0) {
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=n;++i) {
        int ss=min(s,b[i]-a[i]);
        s-=ss;
        ans[i]+=ss;
    }
    if (s) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}