#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005][30],ans[100005];
int x[200005],y[200005],v[200005];
vector <int> oth[100005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=q;i++) scanf("%d%d%d",&x[i],&y[i],&v[i]);
        memset(a,-1,sizeof(a));
        for(int i=0;i<30;i++){
            for(int j=1;j<=n;j++) oth[j].clear();
            for(int j=1;j<=q;j++) {
                if (!(v[j] & (1 << i)))
                    a[x[j]][i] = a[y[j]][i] = 0;
                else if(x[j]==y[j]) a[x[j]][i]=1;
                else oth[min(x[j],y[j])].push_back(max(x[j],y[j]));
            }
            for(int j=1;j<=n;j++) {
                if (a[j][i] == 0) for (auto t:oth[j]) a[t][i] = 1;
                else if(a[j][i]==-1){
                    int fl=0;
                    for(auto t:oth[j]) if(a[t][i]==0) fl=1;
                    //cout<<j<<" "<<fl<<endl;
                    if(fl) a[j][i]=1;
                    else{
                        a[j][i]=0;
                        for(auto t:oth[j]) a[t][i]=1;
                    }
                }
            }
            //for(int j=1;j<=n;j++) cout<<a[j][i]<<" ";puts("");
            for(int j=1;j<=n;j++) ans[j]+=(1<<i)*a[j][i];
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    }
    return 0;
}