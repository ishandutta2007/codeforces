#include<bits/stdc++.h>
using namespace std;

int n;
string s,t;
set<int> l[256],r[256],ll,rr;
vector<int> outl,outr;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        l[s[i]].insert(i+1);
        r[t[i]].insert(i+1);
    }
    for(int i='a';i<='z';i++){
        while(!l[i].empty()&&!r[i].empty()){
            outl.push_back(*l[i].begin());
            outr.push_back(*r[i].begin());
            l[i].erase(l[i].begin());
            r[i].erase(r[i].begin());
        }
        while(!l[i].empty()){
            ll.insert(*l[i].begin());
            l[i].erase(l[i].begin());
        }
        while(!r[i].empty()){
            rr.insert(*r[i].begin());
            r[i].erase(r[i].begin());
        }
    }
    int i='?';
    while(!l[i].empty()&&!rr.empty()){
        outl.push_back(*l[i].begin());
        outr.push_back(*rr.begin());
        l[i].erase(l[i].begin());
        rr.erase(rr.begin());
    }
    while(!r[i].empty()&&!ll.empty()){
        outl.push_back(*ll.begin());
        outr.push_back(*r[i].begin());
        ll.erase(ll.begin());
        r[i].erase(r[i].begin());
    }
    while(!l[i].empty()&&!r[i].empty()){
        outl.push_back(*l[i].begin());
        outr.push_back(*r[i].begin());
        l[i].erase(l[i].begin());
        r[i].erase(r[i].begin());
    }
    cout<<outr.size()<<endl;
    for(int i=0;i<outl.size();i++){
        cout<<outl[i]<<' '<<outr[i]<<endl;
    }
    
    return 0;
}