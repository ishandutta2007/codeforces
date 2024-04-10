#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sit set<int>::iterator
#define ll long long
using namespace std;
const int N=1e6+6;
int a[N],l[N],r[N];
int main(){
    int n; cin>>n;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    int ans=0;
    for (int j=0;j<=24;++j){
        int c0=0,c1=0;
        for (int i=1;i<=n;++i)
            if (a[i]>>j&1) r[++c1]=a[i]%(1<<j);
            else l[++c0]=a[i]%(1<<j);
        if (c0) sort(l+1,l+1+c0);
        if (c1) sort(r+1,r+1+c1);
        long long s=0;
        for (int i=1;i<=c0;++i){
            s+=lower_bound(r+1,r+1+c1,(1<<j)-l[i])-r-1;
            int t=lower_bound(l+1,l+1+c0,(1<<j)-l[i])-l;
            s+=c0-max(i+1,t)+1;
        }
        for (int i=1;i<=c1;++i){
            int t=lower_bound(r+1,r+1+c1,(1<<j)-r[i])-r;
            s+=c1-max(i+1,t)+1;
        }
        if (s&1) ans|=1<<j;
    }
    cout<<ans<<endl;
}
/*
2
8388608 8388608
*/