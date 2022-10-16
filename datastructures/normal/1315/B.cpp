#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long 
using namespace std;
int t,n,a,b,p;
char s[100005];
inline bool check(int i){
    int nowp=0;
    for (;i<n;){
        if (s[i]=='A')nowp+=a;
        else nowp+=b;
        int j=i+1;
        while(j<n&&s[j]==s[i])j++;
        i=j;
    }
    return nowp<=p;
} 
signed main(){
    cin>>t;
    while(t--){
        cin>>a>>b>>p;
        scanf("%s",s+1);
        n=strlen(s+1);
        int l=1,r=n,ans=n;
        while(l<=r){
            int mid=(l+r)/2;
            if (check(mid))r=mid-1,ans=mid;
            else l=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}