#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,a[N],T,k;
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]=x<k?0:x>k?2:1;
    if(n==1&&a[1]==1){puts("yes");return;}
    bool fl=0,fll=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1)fl=1;
        if(a[i]>=1&&(i>1&&a[i-1]>=1||i<n&&a[i+1]>=1))fll=1;
        if(!a[i]&&i>1&&i<n&&a[i-1]>=1&&a[i+1]>=1)fll=1;
    }
    if(!fl)puts("no");
    else if(fll)puts("yes");
    else puts("no");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}