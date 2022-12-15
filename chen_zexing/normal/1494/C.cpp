#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[200005],b[200005];
int aa[200005],bb[200005],suf[200005];
unordered_map<int,int> mp;
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        mp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        int x=0,y=0;
        for(int i=1;i<=n;i++) if(a[i]>0) aa[++x]=a[i];
        for(int i=1;i<=m;i++) if(b[i]>0) bb[++y]=b[i],mp[b[i]]=1;
        suf[x+1]=0;
        for(int i=x;i>=1;i--) suf[i]=suf[i+1]+mp[aa[i]];
        int mx=0,ans=0,now=0;
        //for(int i=1;i<=x;i++) cout<<aa[i]<<" ";puts("");
        if(x&&y) {
            for (int i = 1; i <= y; i++) {
                if (aa[1] > bb[i]) continue;
                int l = 1, r = x;
                aa[x + 1] = INT_MAX;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (bb[i] + mid - 1 < aa[mid + 1]) r = mid;
                    else l = mid + 1;
                    //cout<<bb[i]+mid-1<<" "<<aa[mid+1]<<" "<<mid<<endl;
                }
                while (bb[now] <= bb[i] + l - 1 && now <= y) now++;
                now--;
                mx = max(mx, now - i + 1 + suf[l + 1]);
                //if(mx==now-i+1) cout<<i<<" "<<now<<" "<<l<<endl;
            }
        }
        //cout<<mx<<endl;
        x=y=0;
        ans=mx;
        mx=now=0;
        mp.clear();
        for(int i=n;i>=1;i--) if(a[i]<0) aa[++x]=-a[i];
        for(int i=m;i>=1;i--) if(b[i]<0) bb[++y]=-b[i],mp[-b[i]]=1;
        suf[x+1]=0;
        for(int i=x;i>=1;i--) suf[i]=suf[i+1]+mp[aa[i]];
        if(x&&y) {
            for (int i = 1; i <= y; i++) {
                if (aa[1] > bb[i]) continue;
                int l = 1, r = x;
                aa[x + 1] = INT_MAX;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (bb[i] + mid - 1 < aa[mid + 1]) r = mid;
                    else l = mid + 1;
                }
                while (bb[now] <= bb[i] + l - 1 && now <= y) now++;
                now--;
                mx = max(mx, now - i + 1 + suf[l + 1]);
                //cout<<now<<" "<<i<<" "<<suf[now+1]<<endl;
            }
        }
        printf("%d\n",mx+ans);
    }
    return 0;
}