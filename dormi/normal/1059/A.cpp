#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,l,a;
    cin>>n>>l>>a;
    int lasttime=0;
    int st,am;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>st>>am;
        int breaktime=st-lasttime;
        ans+=breaktime/a;
        lasttime=st+am;
    }
    ans+=(l-lasttime)/a;
    printf("%d\n",ans);
    return 0;
}