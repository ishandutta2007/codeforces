#include <bits/stdc++.h>
using namespace std;


int x,y,xx,yy,xx2,yy2;

inline bool f(int xx,int yy,int xx2,int yy2){
    if (xx+xx2<=x && max(yy,yy2)<=y) {
        cout<<"YES";
        exit(0);
    }
    if (xx+xx2<=y && max(yy,yy2)<=x) {
        cout<<"YES";
        exit(0);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>xx>>yy>>xx2>>yy2;
    f(xx,yy,xx2,yy2);
    f(xx,yy,yy2,xx2);
    f(yy,xx,xx2,yy2);
    f(yy,xx,yy2,xx2);
    cout<<"NO";
}