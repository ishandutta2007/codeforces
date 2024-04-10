#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &x:a)cin>>x;
    int ans=0;
    for(int i=a.size()-2;i>=0;i--){
        if(a[i+1]==0){
            cout<<"-1\n";
            return;
        }
        while(a[i]>=a[i+1]){
            a[i]/=2;
            ans++;
        }
    }
    cout<<ans<<'\n';
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