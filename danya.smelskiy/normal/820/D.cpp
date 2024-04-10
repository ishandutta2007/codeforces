#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
int pos[1000001];
long long last;
long long p[1000001];
long long z[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for (int i=1;i<=n;++i) {
        if (i>a[i]) {
            long long x=abs(a[i]-i);
            p[0]+=x;
            ++z[0];
            int pos=n-i;
            --z[pos];
            ++pos;
            p[pos]-=x+pos-1;
            if (a[i]>1) {
                long long x=abs(1-a[i]);
                --z[pos];
                p[pos]+=x;
                pos+=a[i]-1;
                ++z[pos];
            }
            ++z[pos];
        } else {
            long long x=abs(a[i]-i);
            p[0]+=x;
            --z[0];
            int ppos=a[i]-i;
            ++z[ppos];
            if (a[i]!=n) {
                ++z[ppos];
                ppos=n-i;
                z[ppos]--;
                p[ppos+1]-=n-a[i];
            }
            ++ppos;
            p[ppos]+=abs(a[i]-1);
            --z[ppos];
        }
    }
    long long ans=1e18;
    long long k=0;
    long long now=0;
    for (int i=0;i<n;++i){
        now+=last+p[i];
        if (now<ans) {
            ans=now;
            k=i;
        }
        last+=z[i];
    }
    cout<<ans<<" "<<k;
}