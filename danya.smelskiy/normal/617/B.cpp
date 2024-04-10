#include <bits/stdc++.h>
using namespace std;

long long n,x,last,ans;
bool t;
vector<int> v;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==1){
            if (t==true) v.push_back(last);
            t=true;
            last=0;
        } else ++last;
    }
    ++ans;
    if (t==false) ans=0;
    for (int i=0;i<v.size();++i)
        ans*=v[i]+1;
    cout<<ans;
}