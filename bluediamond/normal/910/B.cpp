#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,ans=(1<<30),a,b;
int v[100];

void bkt(int strat,int x,int y) {
    if(strat==6) {
        if(x!=4 || y!=2) {
            return;
        }
        int cost=0,cur=0;
        for(int i=1;i<=6;i++) {
            if(v[i]==1) {
                if(cur>=a) {
                    cur-=a;
                }
                else {
                    cost++;
                    cur=n-a;
                }
            }
            else {
                if(cur>=b) {
                    cur-=b;
                }
                else {
                    cost++;
                    cur=n-b;
                }
            }
        }
        ans=min(ans,cost);
        return;
    }
    v[strat+1]=1; bkt(strat+1,x+1,y);
    v[strat+1]=2; bkt(strat+1,x,y+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    bkt(0,0,0);
    cout<<ans<<"\n";
    return 0;
}

/**



**/