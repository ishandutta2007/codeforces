#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,string> a[3005];
pair<string,int> ans[3005],ans2[3005];
int last;

inline void ins(int sz,int x,string ss) {
    for (int i=1;i<=sz;++i)
        ans2[i]=ans[i];
    int h;
    h=--last;
    ans[x+1]=make_pair(ss,h);
    int sz2=x+1;
    for (int i=x+1;i<=sz;++i)
        ans[++sz2]=ans2[i];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].second>>a[i].first;
    }
    sort(a+1,a+n+1);
    last=n+n;
    int sz=0;
    for (int i=1;i<=n;++i) {
        int x=a[i].first;
        if (x>sz) {
            cout<<"-1";
            return 0;
        }
        if (x==sz) {
            ans[++sz]=make_pair(a[i].second,--last);
        } else ins(sz,a[i].first,a[i].second),++sz;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';

}