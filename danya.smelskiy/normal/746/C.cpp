#include <bits/stdc++.h>
using namespace std;
long long ans;
bool tt;
long long n,x,y,t,t2,xx,yy,l;
int main(){
    cin>>n>>x>>y;
    cin>>t>>t2;
    cin>>xx>>yy;
    l=abs(x-y)*t2;
    if (xx==x) tt=true;
    while (true){
        if (yy==-1) --xx;
        else ++xx;
        ans+=t;
        if (xx==x) tt=true;
        if (xx==y && tt==true) {
            cout<<min(ans,l);
            return 0;
        }
        if (xx==0) yy=1;
        else if (xx==n) yy=-1;
    }
}