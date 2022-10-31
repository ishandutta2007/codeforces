#include<bits/stdc++.h>
using namespace std;
#define N 100005
set<int>GT;
set<int>::iterator gt;
vector<int>A[N];
#define pb push_back
int a[N],b[N],id[N],F[N],L[N],d[N],n,f[N],Ans[N],ans;
inline bool work(int x) {
    int R=0;
    for (int i=1;i<=n;i++) {
        if (b[i]) continue;
        int s=0,l=1,r=R;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (a[i]>F[mid]) s=mid,l=mid+1;
            else r=mid-1;
        }
        if (s<R)
            F[s+1]=min(F[s+1],a[i]);
        else F[s+1]=a[i],R=s+1;
        L[a[i]]=F[s];
    }
    int tmp=f[n]-x+1;
    GT.clear();
    if (R<=tmp) {

        for (int i=n;i;i--) {
            if (b[i]) continue;
            gt=GT.lower_bound(a[i]);
            if (gt==GT.begin()) {
                ans++;
                Ans[x]=1;
                A[x].pb(i);
                d[i]=x;
                GT.insert(a[i]);
                x++;
            }
            else {
                gt--;
                int p=id[(*gt)];
                GT.erase(gt);
                p=d[p];
                Ans[p]++;
                d[i]=p;
                GT.insert(a[i]);
                A[p].pb(i);
            }
        }
        return 1;
    }
    else {
        ans++;
        Ans[x]=R;
        for (int i=F[R];i;) {
            A[x].pb(id[i]);
            b[id[i]]=1;
            i=L[i];
        }
        return 0;
    }
}
int main() {
//    freopen("0.in","r",stdin);
    int test;
    int j=1;
    for (int i=1;i<=100000;i++) {
        while ((j+1)*(j+2)/2<=i) j++;
        f[i]=j;
    }
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]),id[a[i]]=i,b[i]=0;
        int s=0;
        ans=0;
        for (int i=1;i<=f[n];i++) {
            s=work(i);
            if (s) break;
        }
        assert(ans<=f[n]);
        printf("%d\n",ans);
        for (int i=1;i<=ans;i++) {
            printf("%d ",Ans[i]);
            for (int j=Ans[i]-1;j>=0;j--) printf("%d ",a[A[i][j]]);
            A[i].clear();
            puts("");
        }
    }
return 0;
}