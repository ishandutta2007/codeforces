#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1005][1005];
int n,m,ans,a[1005];
signed main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for (int i=1;i<=m;i++)cin>>a[i];
    for (int i=1;i<=m;i++){
        int mx[15]={0},mxx=0;
        for (int j=1;j<=n;j++)
            mx[s[j][i]-'A']++;
        for (int j=0;j<5;j++)mxx=max(mxx,mx[j]);
        ans+=a[i]*mxx;
    }
    cout<<ans<<endl;
    return 0;
}