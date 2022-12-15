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
int a[2005],cnt[1000005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
        sort(a+1,a+n*2+1);
        int f=0;
        for(int i=1;i<=n*2-1;i++){
            int fl=1;
            for(int j=1;j<=n*2;j++) cnt[a[j]]=0;
            priority_queue <int> q;
            while(!q.empty()) q.pop();
            for(int j=1;j<=n*2;j++) if(j!=i) cnt[a[j]]++,q.push(a[j]);
            int now=q.top();
            //cout<<now<<endl;
            q.pop();
            cnt[now]--;
            for(int j=n-1;j>=1;j--){
                int t=q.top();
                while(cnt[t]==0) {
                    q.pop();
                    t=q.top();
                }
                cnt[t]--;
                //cout<<t<<endl;
                if(cnt[now-t]){
                    cnt[now-t]--;
                    now=t;
                }
                else{
                    fl=0;
                    break;
                }
            }
            if(fl){
                f=1;
                puts("YES");
                for(int j=1;j<=n*2;j++) cnt[a[j]]=0;
                while(!q.empty()) q.pop();
                for(int j=1;j<=n*2;j++) if(j!=i) cnt[a[j]]++,q.push(a[j]);
                now=q.top();
                //cout<<now<<endl;
                q.pop();
                cnt[now]--;
                printf("%d\n%d %d\n",now+a[i],now,a[i]);
                for(int j=n-1;j>=1;j--){
                    int t=q.top();
                    while(cnt[t]==0) {
                        q.pop();
                        t=q.top();
                    }
                    cnt[t]--;
                    //cout<<t<<endl;
                    if(cnt[now-t]){
                        cnt[now-t]--;
                        printf("%d %d\n",t,now-t);
                        now=t;
                    }
                    else{
                        fl=0;
                        break;
                    }
                }
                break;
            }
        }
        if(!f) puts("NO");
        for(int i=1;i<=n*2;i++) cnt[a[i]]=0;
    }
    return 0;
}