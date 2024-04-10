#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int a[105],s[105];
int t,x,n,c;
signed main(){
    cin>>t;
    while(t--){
        cin>>x>>n;
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for (int i=1ll;i<=n;i++){
            cin>>c;
            for (int j=0ll;j<=62ll;j++){
                if ((1ll<<j)==c){
                    s[j]++;
                    break;
                }
            }
        }
        for (int i=62ll;i>=0ll;i--){
            if ((1ll<<i)<=x)x-=(1ll<<i),a[i]=1ll;
        }
        int ans=0ll,now=0ll,flag=1ll;
        for (int i=0ll;i<=62ll;i++){
            if (i==62ll&&s[i]<0ll)flag=0ll;
            s[i]-=a[i];
            now/=2ll; 
            if (s[i]>=0ll)now+=s[i];
            else{
                if (s[i]+now>=0ll)now-=0-s[i],s[i]=0;
                else{
                    s[i]+=now;now=0ll;
                    int change=(-s[i]-1ll)/2ll+1ll;
                    ans+=change;
                    s[i+1]-=(-s[i]-1ll)/2ll+1ll;
                    s[i]+=change*2ll;
                    now+=s[i];
                }
            } 
        }
        if (flag==0ll)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}