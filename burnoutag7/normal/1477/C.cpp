#include<bits/stdc++.h>
using namespace std;

long long dist(const pair<int,int> &x,const pair<int,int> &y){
    return (long long)abs(x.first-y.first)*abs(x.first-y.first)+(long long)abs(x.second-y.second)*abs(x.second-y.second);
}

int n;
pair<int,int> p[5005],cp;
set<int> s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        s.insert(i);
    }
    for(int i=1;i<=n;i++){
        int c=*s.begin();
        for(const int &x:s)if(dist(p[x],cp)>dist(p[c],cp))c=x;
        s.erase(c);
        cout<<c<<' ';
        cp=p[c];
    }

    return 0;
}