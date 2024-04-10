#include<bits/stdc++.h>
using namespace std;

int a,b;

void mian(){
    cin>>a>>b;
    int n=a+b,as=(n+1)/2,bs=n/2;
    set<int> s;
    for(int i=max(0,a-bs);i<=min(a,as);i++)s.emplace(i+bs-(a-i));
    for(int i=max(0,b-bs);i<=min(b,as);i++)s.emplace(i+bs-(b-i));
    cout<<s.size()<<'\n';
    for(int x:s)cout<<x<<' ';
    cout<<'\n';
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