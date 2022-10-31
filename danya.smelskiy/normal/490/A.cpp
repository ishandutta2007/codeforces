#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int> a,b,c;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==1) a.push_back(i);
        else if (x==2) b.push_back(i);
        else c.push_back(i);
    }
    cout<<min(a.size(),min(b.size(),c.size()))<<endl;
    for (int i=0;i<min(a.size(),min(b.size(),c.size()));++i){
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    }
}