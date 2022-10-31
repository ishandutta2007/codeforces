#include <bits/stdc++.h>
using namespace std;
long long n,x;
vector<int> v;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        bool t=false;
        for (int j=1;j<=n;++j){
            cin>>x;
            if (x==1 || x==3) t=true;
        }
        if (t==false) v.push_back(i);
    }
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}