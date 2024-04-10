#include<bits/stdc++.h>
using namespace std;

int n,x,y;

void mian(){
    cin>>n>>x>>y;
    for(int d=1;d<=y-x;d++)if((y-x)%d==0&&(y-x)/d<n){
        int cnt=0,cur=y;
        while(cur>0&&cnt<n)cout<<cur<<' ',cur-=d,cnt++;
        cur=y;
        while(cnt<n)cout<<(cur+=d)<<' ',cnt++;
        cout<<'\n';
        return;
    }
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