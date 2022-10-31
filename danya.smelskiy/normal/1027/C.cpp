#include <bits/stdc++.h>
using namespace std;




int n;
int a[1000005];
int sz;
int q[1000005];



inline double f(double x,double y) {
    double res=x/y;
    res+=y/x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    long double mn,cur;
    int a1,a2;
    while (t--) {
        cin>>n;
        for (int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        int ii=2;
        sz=0;
        while (ii<=n) {
            if (a[ii]==a[ii-1]) {
                q[++sz]=a[ii];
                ii+=2;
            } else {
                ++ii;
            }
        }
        sort(q+1,q+sz+1);
        int l=1;
        mn=1e18;
        for (int i=2;i<=sz;++i) {
            while (l<i-1 && f(q[l+1],q[i])<=f(q[l],q[i])) ++l;
            cur=f(q[l],q[i]);
            if (cur<mn) {
                mn=cur;
                a1=q[l];
                a2=q[i];
            }
        }
        cout<<a1<<" "<<a1<<" "<<a2<<" "<<a2<<'\n';
    }
}