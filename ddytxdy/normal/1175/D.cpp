#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50;
int n,k,a[N];LL s[N],ans;
bool cmp(LL x,LL y){
    return x>y;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i;i--)s[i]=s[i+1]+a[i];
    ans=s[1];
    sort(s+2,s+n+1,cmp);
    for(int i=2;i<=k;i++)ans+=s[i];
    cout<<ans;
    return 0;
}