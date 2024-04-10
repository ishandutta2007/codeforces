#include <bits/stdc++.h>
using namespace std;
int x,y,x2,y2,l;
int main(){
    cin>>x>>y>>x2>>y2;
    if (x!=x2 && y!=y2 && abs(y2-y)!=abs(x2-x)) cout<<"-1";
    else if (x!=x2 && y!=y2){
        cout<<x<<" "<<y2<<" "<<x2<<" "<<y;
    } else if (x==x2){
        if (y>y2) swap(y,y2);
        l=y2-y;
       cout<<x+l<<" "<<y<<" "<<x2+l<<" "<<y2;
    } else {
        if (x>x2) swap(x,x2);
        l=x2-x;
        cout<<x<<" "<<y+l<<" "<<x2<<" "<<y2+l;
    }
}