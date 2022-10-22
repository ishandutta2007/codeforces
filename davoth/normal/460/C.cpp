#include <bits/stdc++.h>
using namespace std;
long long n,m,w;
long long a[(int)1e5+10],b[(int)1e5+10];
bool check(long long k){
    long long c=0,s=0;
    for(long long i=0; i<n; i++){
        c-=b[i];
        long long am=max((long long)0,k-(c+a[i]));
        b[min(i+w,n)]=am;
        c+=am;
        s+=am;
        if(s>m) return false;
    }
    return true;
}
int main() {
    cin >> n >> m >> w;
    for(int i=0; i<n; i++) cin >> a[i];
    long long r=1e15,l=0;
    while(r-l>1){
        long long mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout << l;
    return 0;
}