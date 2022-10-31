#include <bits/stdc++.h>
using namespace std;


int n,d,l;
int ans[105];
int s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>d>>l;
    int mn=(n+1)/2-((n/2)*l);
    int mx=((n+1)/2)*l-(n)/2;
    if (d<mn || d>mx) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;++i) {
        ans[i]=1;
        if (i&1) ++s;
        else --s;
    }
    int last1=1;
    int last2=2;
    while (s!=d) {
        if (s>d) {
            if (ans[last2]==l) last2+=2;
            ans[last2]++;
            --s;
        } else {
            if (ans[last1]==l) last1+=2;
            ans[last1]++;
            ++s;
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}