#include<bits/stdc++.h>
using namespace std;

int n,a[55];
set<int> s;

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    s.clear();
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)s.insert(a[j]-a[i]);
    cout<<s.size()<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}