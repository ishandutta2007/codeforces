#include<bits/stdc++.h>
using namespace std;

int q,x,y,f;
set<int> t[400005];
int p[400005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q>>x;
    for(int i=0;i<x;i++)t[0].insert(i);
    while(q--){
        cin>>y;y=y%x;
        t[p[y]].erase(y);
        p[y]++;
        t[p[y]].insert(y);
        while(t[f].empty())f++;
        cout<<f*x+*t[f].begin()<<endl;
    }

    return 0;
}