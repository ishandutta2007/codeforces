#include <bits/stdc++.h>
using namespace std;


int c[10000];
inline void f(vector<int> a,vector<int> b){
    bool t=false;
    vector<int> c;
    for (int i=2;i<a.size();++i)
        c.push_back(a[i]);
    for (int i=0;i<2;++i)
        c.push_back(a[i]);
    for (int i=0;i<c.size();++i) {
        if (c[i]!=b[i]) t=true;
    }
    if (!t) {
        cout<<"YES";
        exit(0);
    }
    t=false;
    c.clear();
    for (int i=2;i<b.size();++i)
        c.push_back(b[i]);
    for (int i=0;i<2;++i)
        c.push_back(b[i]);
    for (int i=0;i<c.size();++i)
        if (c[i]!=a[i]) t=true;
    if (!t) {
        cout<<"YES";
        exit(0);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=24;++i)
        cin>>c[i];
    vector<int> v;
    vector<int> vv;
    for (int i=1;i<=12;++i)
        if (i&1) v.push_back(c[i]);
        else vv.push_back(c[i]);
    v.push_back(c[22]);
    v.push_back(c[24]);
    vv.push_back(c[23]);
    vv.push_back(c[21]);
    f(v,vv);


    v.clear();
    vv.clear();
    v.push_back(c[13]);
    v.push_back(c[14]);
    v.push_back(c[5]);
    v.push_back(c[6]);
    v.push_back(c[17]);
    v.push_back(c[18]);
    v.push_back(c[21]);
    v.push_back(c[22]);

    vv.push_back(c[15]);
    vv.push_back(c[16]);
    vv.push_back(c[7]);
    vv.push_back(c[8]);
    vv.push_back(c[19]);
    vv.push_back(c[20]);
    vv.push_back(c[23]);
    vv.push_back(c[24]);
    f(v,vv);
    v.clear();
    vv.clear();
    v.push_back(c[3]);
    v.push_back(c[4]);
    v.push_back(c[17]);
    v.push_back(c[19]);
    v.push_back(c[9]);
    v.push_back(c[10]);
    v.push_back(c[14]);
    v.push_back(c[16]);

    vv.push_back(c[1]);
    vv.push_back(c[2]);
    vv.push_back(c[18]);
    vv.push_back(c[20]);
    vv.push_back(c[11]);
    vv.push_back(c[12]);
    vv.push_back(c[13]);
    vv.push_back(c[15]);
    f(v,vv);
    cout<<"NO";
}