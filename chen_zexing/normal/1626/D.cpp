#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int a[200005],cnt[200005];
int b[200005];
int mn[200005],pre[200005];
int pos[21];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        int x=0;
        for(int i=1;i<=n;i++) if(cnt[i]) b[++x]=cnt[i];
        for(int i=1;i<=x;i++) pre[i]=pre[i-1]+b[i];
        mn[0]=2;
        int ub=0;
        while((1<<ub)<n*2) ub++;
        int now=0,sum=0;
        for(int i=0;i<=ub;i++){
            while(now<x&&sum+b[now+1]<=(1<<i)) now++,sum+=b[now];
            pos[i]=now;
            //cout<<i<<" "<<pos[i]<<" "<<sum<<b[now+1]<<" "<<endl;
        }
        //for(int i=0;i<=ub;i++) cout<<pos[i]<<" ";
        for(int i=1;i<=x;i++) mn[i]=INT_MAX/2;
        for(int i=1;i<=x;i++){
            for(int j=0;j<=ub;j++){
                int rest=pre[i]-pre[min(pos[j],i)];
                int v=1;
                while(v<rest) v*=2;
                mn[i]=min(mn[i],(1<<j)+v);
            }
        }
        //puts("");
        int ans=INT_MAX;
        for(int i=0;i<=x;i++){
            int v=1;
            while(v<pre[x]-pre[i]) v*=2;
            //cout<<mn[i]<<" "<<v<<endl;
            ans=min(ans,v+mn[i]);
        }
        printf("%d\n",ans-n);
    }
    return 0;
}