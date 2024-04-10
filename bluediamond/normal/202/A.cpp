#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string a,ans;
int n;

void bkt(int strat,int l,string cur) {
    if(strat==n) {
        for(int i=0;i<l-i-1;i++)
            if(cur[i]!=cur[l-i-1])
                return;
        ans=max(ans,cur);
    }
    else {
        bkt(strat+1,l,cur);
        bkt(strat+1,l+1,cur+a[strat]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    ans=a[0];
    n=a.size();
    bkt(0,0,"");
    cout<<ans<<"\n";
    return 0;
}
/**


**/