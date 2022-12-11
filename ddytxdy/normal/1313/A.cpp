#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,ans;
int main(){
    scanf("%d",&t);
    while(t--){ans=0;
        scanf("%d%d%d",&a,&b,&c);
        if(a<b)swap(a,b);if(b<c)swap(b,c);if(a<b)swap(a,b);
        if(a>=1)ans++,a--;
        if(b>=1)ans++,b--;
        if(c>=1)ans++,c--;
        if(a>=1&&b>=1)ans++,a--,b--;
        if(a>=1&&c>=1)ans++,a--,c--;
        if(b>=1&&c>=1)ans++,b--,c--;
        if(a>=1&&b>=1&&c>=1)ans++;
        cout<<ans<<endl;
    }
    return 0;
}