#include <bits/stdc++.h>
using namespace std;

bitset<1000005> b;
int n,k;
int a[1000005];
int kol[1000005];
bool used[1000005];
int kol1,kol2;
inline void add(int x){
    b=(b|(b>>x));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    b.set(n);
    for (int i=1;i<=n;++i) if (used[i]==false) {
        int l=0;
        int x=i;
        while (used[x]==false) {
            ++l;
            used[x]=true;
            x=a[x];
        }
        ++kol[l];
        kol1+=l/2; kol2+=l%2;
    }
    for (int i=1;i<=n;++i)
    if (kol[i]) {
        int sz=1;
        while (sz<=kol[i]) {
            add(sz*i);
            kol[i]-=sz;
            sz*=2;
        }
        if (kol[i]) add(kol[i]*i);
    }
    cout<<(k+(1-b.test(k)))<<" ";
    int res=kol1;
    res=min(res,k);
    int res2=res*2;
    k-=res;
    res2+=min(k,kol2);
    cout<<res2;
}