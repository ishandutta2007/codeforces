#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int T,n,a[N];char s[N];
void solve(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)a[i]=n-i+1;
    for(int i=1,j;i<=n;i++){
        if(s[i]=='>')continue;
        j=i;while(j<=n&&s[j]=='<')j++;
        reverse(a+i,a+j+1);
        i=j;
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1,j;i<=n;i++){
        if(s[i]=='<')continue;
        j=i;while(j<=n&&s[j]=='>')j++;
        reverse(a+i,a+j+1);
        i=j;
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}