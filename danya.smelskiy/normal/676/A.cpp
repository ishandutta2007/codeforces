#include <bits/stdc++.h>
using namespace std;
int n,ans,x,pos1,pos2,maxim,minim=10e5+1;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
            cin>>x;
            if (x<minim) { minim=x; pos1=i;}
            if (x>maxim) { maxim=x; pos2=i;}
    }
    ans=abs(pos2-pos1);
    if (pos1!=n) ans=max(ans,abs(n-pos2));
    if (pos2!=n) ans=max(ans,abs(n-pos1));
    if (pos2!=1) ans=max(ans,abs(pos1-1));
    if (pos1!=1) ans=max(ans,abs(pos2-1));
    cout<<ans;
}