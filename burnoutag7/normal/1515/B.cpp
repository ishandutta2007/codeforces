#include<bits/stdc++.h>
using namespace std;

int n;

bool f(int x){
    int y=sqrt(x);
    while(y*y<x)y++;
    while(y*y>x)y--;
    return y*y==x;
}

void mian(){
    cin>>n;
    cout<<(n%2==0&&f(n/2)||n%4==0&&f(n/4)?"YES\n":"NO\n");
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