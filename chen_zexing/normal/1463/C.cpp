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
struct order{
    long long t,to,nxt,pre;
}a[100005];
//
int f[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        long long now=0,t=0;
        cin>>n;
        a[0].nxt=1;
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].t,&a[i].to),a[i].nxt=i+1,a[i].pre=i-1,f[i]=1;
        a[n+1].t=LLONG_MAX/10,a[n+1].nxt=0;
        for(int i=1;a[i].nxt;i=a[i].nxt){
            //cout<<i<<endl;
            //cout<<a[i].t<<" "<<a[a[i].nxt].t<<" "<<now<<endl;
            if(abs(a[i].to-now)<=a[a[i].nxt].t-a[i].t){
                //cout<<i<<" "<<a[i].nxt<<endl;
                if(f[i]) ans++;
                now=a[i].to;
            }
            else{
                long long pos=a[a[i].nxt].to,t=a[a[i].nxt].t;
                if(now<=a[i].to) {if(now+t-a[i].t<=pos&&pos<=now+a[a[i].nxt+1].t-a[i].t&&pos>=now&&pos<=a[i].to) ans++,cout;}
                else if(now-(t-a[i].t)>=pos&&pos>=now-(a[a[i].nxt+1].t-a[i].t)&&pos<=now&&pos>=a[i].to) ans++;
                f[i]=0;
                a[i].nxt=a[a[i].nxt].nxt;
                i=a[i].pre;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}