#include <bits/stdc++.h>
using namespace std;


int a,b;


void prnt(pair<vector<int>,vector<int> > v) {
    cout<<v.first.size()<<'\n';
    for (int i=0;i<v.first.size();++i)
        cout<<v.first[i]<<" ";
    cout<<'\n';
    cout<<v.second.size()<<'\n';
    for (int i=0;i<v.second.size();++i)
        cout<<v.second[i]<<" ";
    cout<<'\n';
    exit(0);
}

inline pair<vector<int>,vector<int> > solve(vector<int> v) {
    pair<vector<int>,vector<int> > res;
    int x=a;
    int y=b;
    for (int i=v.size()-1;i>=0;--i) {
        if (x>=y && x>=v[i]) res.first.push_back(v[i]),x-=v[i];
        else if (y>=v[i]) res.second.push_back(v[i]),y-=v[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
  //  freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    cin>>a>>b;
    int c=a+b;
    vector<int> v;
    int last=1;
    while (last<=c) {
        v.push_back(last);
        c-=last++;
    }
    --last;
    pair<vector<int>,vector<int> > ans=solve(v);
    if (ans.first.size()+ans.second.size()==last) prnt(ans);
    else {
        v.pop_back();
        ans=solve(v);
        prnt(ans);
    }
}