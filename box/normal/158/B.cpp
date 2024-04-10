#include <bits/stdc++.h>
using namespace std;
int main() {
    int o=0,t=0,h=0,f=0;
    int n;cin>>n;
    while(n--){
        int v;cin>>v;
        if(v==1)o++;
        if(v==2)t++;
        if(v==3)h++;
        if(v==4)f++;
    }
    int A=f,r=min(o,h);
    A+=r;h-=r;o-=r;
    A+=(h+t/2);t%=2;
    if(t){if(o){A++;o=max(o-2,0);}else A++;}
    A+=(o+3)/4;
    cout<<A<<endl;
}