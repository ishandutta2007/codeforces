#include <bits/stdc++.h>
using namespace std;


int a[5005];
int n;

inline int get(int l,int r,int x){
    if (l==r) return min(a[l]-x,1);
    int mn=1e9+7;
    for (int i=l;i<=r;++i)
            mn=min(mn,a[i]);
    int last=l-1;
    int now=0;
    for (int i=l;i<=r;++i)
    if (a[i]==mn) {
        now+=get(last+1,i-1,mn);
        last=i;
    }
    if (last!=r) now+=get(last+1,r,mn);
    return min(r-l+1,now+mn-x);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cout<<get(1,n,0);
}