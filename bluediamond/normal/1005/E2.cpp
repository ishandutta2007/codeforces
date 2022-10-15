#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=200000;
int n,v[N+5];
int s[2*N+5];

ll slove(int x) {
    for(int i=0;i<=2*N;i++)
        s[i]=0;
    int sum=n;
    int cur=0;
    s[sum]=1;
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(v[i]<x) {
            sum--;
            cur-=s[sum];
        }
        else {
            cur+=s[sum];
            sum++;
        }
        ans+=cur;
        s[sum]++;
    }
    return ans;
}

int val;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>val;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    ll ans=slove(val)-slove(val+1);
    cout<<ans<<"\n";
    return 0;
}
/**

m = 5

1 4 4 1 => 4

**/