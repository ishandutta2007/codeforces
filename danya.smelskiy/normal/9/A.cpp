#include <bits/stdc++.h>
using namespace std;
long long x,y;
int main(){
    cin>>x>>y;
    long long ans=6-max(x,y);
    if (ans==0) cout<<"1/6";
    else if (ans==1) cout<<"1/3";
    else if (ans==2) cout<<"1/2";
    else if (ans==3) cout<<"2/3";
    else if (ans==4) cout<<"5/6";
    else if (ans==5) cout<<"1/1";
}