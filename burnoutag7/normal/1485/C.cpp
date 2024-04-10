#include<bits/stdc++.h>
using namespace std;

void mian(){
    int x,y,st;
    long long ans=0;
    cin>>x>>y;
    for(int i=1;i*i-1<=x&&i<=y;i++){
        ans+=i-1;
        st=i;
    }
    for(int i=st+1,con=st+1;i<=y;i++){
        while(con*i+con>x)con--;
        if(con==0)break;
        int j=min(x/con-1,y);
        ans+=(long long)con*(j-i+1);
        i=j;
    }
    cout<<ans<<'\n';
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