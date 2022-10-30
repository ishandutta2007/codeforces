#include <bits/stdc++.h>
using namespace std;
long long s,t1,t2,v1,v2;


int main(){
    cin>>s>>t1>>t2>>v1>>v2;
    long long ans1=v1+v1+s*t1;
    long long ans2=v2+v2+s*t2;
    if (ans1==ans2) cout<<"Friendship";
    else if (ans1<ans2) cout<<"First";
    else cout<<"Second";
}