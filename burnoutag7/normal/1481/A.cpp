#include<bits/stdc++.h>
using namespace std;

int x,y,u,d,l,r;

void mian(){
    cin>>x>>y;
    string s;
    cin>>s;
    u=d=l=r=0;
    for(char c:s){
        u+=c=='U';
        d+=c=='D';
        l+=c=='L';
        r+=c=='R';
    }
    x=x-r+l;
    y=y-u+d;
    bool fx=x>0&&l>=x||x<0&&r>=-x||x==0,fy=y>0&&d>=y||y<0&&u>=-y||y==0;
    cout<<(fx&&fy?"YES\n":"NO\n");
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}