#include <bits/stdc++.h>
using namespace std;

long long n,l,r,minim,c[100005];
struct st{
    long long x,y,id;
};
st a[100005];

inline bool cmp(st a,st b){
    return a.y<b.y;
}
int main(){
    cin>>n>>l>>r;
    for (int i=1;i<=n;++i){
        cin>>a[i].x;
    }
    for (int i=1;i<=n;++i){
        cin>>a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    minim=-1000000000;
    for (int i=1;i<=n;++i){
        long long ll=l;
        long long rr=r;
        while (ll<rr-1){
            long long mid=(ll+rr)/2;
            if (mid-a[i].x>minim) rr=mid;
            else ll=mid;
        }
        if (rr-a[i].x<=minim) {
            cout<<"-1";
            return 0;
        }
        if (ll-a[i].x>minim) rr=ll;
        c[a[i].id]=rr;
        minim=rr-a[i].x;
    }
    for (int i=1;i<=n;++i)
        cout<<c[i]<<" ";
}