#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define int long long
using namespace std;
int q,n,t[105],l[105],r[105];
signed main(){
    cin>>q;
    while(q--){
        int now=0,flag=1;
        cin>>n>>now;
        int nowl=now,nowr=now;
        for (int i=1;i<=n;i++)cin>>t[i]>>l[i]>>r[i];
        for (int i=1;i<=n;i++){
            nowl-=t[i]-t[i-1],nowr+=t[i]-t[i-1];
            if (nowl>r[i]||nowr<l[i])flag=0;
            nowl=max(nowl,l[i]),nowr=min(nowr,r[i]);
        }
        if (flag==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}