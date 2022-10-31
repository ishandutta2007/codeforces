#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e4+5;
pair<int,int> a[maxn];
int ans[maxn],step[maxn],f[maxn],l[maxn],r[maxn],last[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].first),a[i].second=i;
    sort(a+1,a+1+n);
    f[0]=1,f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])%m;
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l[i],&r[i]);
        last[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int d = a[i].first % m;
        for(int j=1;j<=q;j++){
            if(a[i].second<l[j]||a[i].second>r[j])continue;
            if(a[i].first==last[j])continue;
            ans[j]=(ans[j]+f[step[j]++]*d)%m;
            last[j]=a[i].first;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
}