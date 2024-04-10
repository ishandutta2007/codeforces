#include<bits/stdc++.h>
using namespace std;

int n,sx,sy;
int x[200005],y[200005];
int l,r,u,d;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>sx>>sy;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        if(x[i]>sx)r++;
        if(x[i]<sx)l++;
        if(y[i]>sy)u++;
        if(y[i]<sy)d++;
    }
    if(r>=l&&r>=r&&r>=u&&r>=d){
        cout<<r<<endl;
        cout<<sx+1<<' '<<sy<<endl;
    }else
    if(l>=l&&l>=r&&l>=u&&l>=d){
        cout<<l<<endl;
        cout<<sx-1<<' '<<sy<<endl;
    }else
    if(u>=l&&u>=r&&u>=u&&u>=d){
        cout<<u<<endl;
        cout<<sx<<' '<<sy+1<<endl;
    }else
    if(d>=l&&d>=r&&d>=u&&d>=d){
        cout<<d<<endl;
        cout<<sx<<' '<<sy-1<<endl;
    }

    return 0;
}