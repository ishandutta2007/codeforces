#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
vector<int> v;
long long last=1;
long long a[100001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        bool t=false;
        for (int j=last;j<a[i];++j){
            if (j<=m){
                ++ans;
                m-=j;
                v.push_back(j);
            } else {
            t=true;
            break;}
        }
        if (t==true) break;
        last=a[i]+1;
    }
    last=a[n]+1;
    while (last<=m){
        v.push_back(last);
        ++ans;
        m-=last;
        last++;
    }
    cout<<ans<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}