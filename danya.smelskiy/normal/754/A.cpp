#include <bits/stdc++.h>
using namespace std;
bool t;
long long n,a[10000],last,kk;
vector<long long> v;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        if (a[i]!=0) t=true;
    }
    if (t==false){
        cout<<"NO";
        return 0;
    }
    last=0;
    for (int i=1;i<=n;++i){
        last+=a[i];
        if (last!=0){
            v.push_back(i);
            last=0;
            kk=i;
        }
    }
    if (kk<n){
        if (v.size()==0){
            cout<<"NO";
            return 0;
        } else
        v[v.size()-1]=n;
    }
    last=0;
    cout<<"YES"<<'\n';
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i){
        cout<<last+1<<" "<<v[i]<<'\n';
        last=v[i];
    }

}