#include<bits/stdc++.h>
using namespace std;

int dis[2][2];

int main(){

    cout<<"? 1 1\n";
    cin>>dis[0][0];
    cout<<"? 1 1000000000\n";
    cin>>dis[0][1];
    cout<<"? 1000000000 1\n";
    cin>>dis[1][0];
    cout<<"? 1000000000 1000000000\n";
    cin>>dis[1][1];
    cout<<"? 1 "<<(1+dis[0][0]+1000000000-dis[0][1])/2<<"\n";
    int u;
    cin>>u;
    u++;
    cout<<"? 1000000000 "<<(1+dis[1][0]+1000000000-dis[1][1])/2<<"\n";
    int d;
    cin>>d;
    d=1000000000-d;
    int l;
    cout<<"? "<<(1+dis[0][0]+1000000000-dis[1][0])/2<<" 1\n";
    cin>>l;
    l++;
    int r;
    cout<<"? "<<(1+dis[0][1]+1000000000-dis[1][1])/2<<" 1000000000\n";
    cin>>r;
    r=1000000000-r;
    cout<<"! "<<u<<" "<<l<<" "<<d<<" "<<r<<"\n";

    return 0;
}