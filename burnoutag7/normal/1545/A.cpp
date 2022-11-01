#include<bits/stdc++.h>
using namespace std;

int n;

void mian(){
    int n;
    cin>>n;
    vector<int> a(n),b,c;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&1)b.emplace_back(a[i]);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i&1)c.emplace_back(a[i]);
    }
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    cout<<(b==c?"YES\n":"NO\n");
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