#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int T,n,a[N],st[N],tp,np[N],xp[N];
void solve(){
    scanf("%d",&n);bool fl=1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    puts(a[1]<a[n]?"YES":"NO");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}