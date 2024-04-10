#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,a;
    map<int,int> mp;
    cin>>n;
    while(n--)cin>>a,mp[a]++;
    int ans=-1;
    for(int i=0;;i++)if(mp[i]<2){
        if(ans!=-1){
            if(mp[i]==0){
                cout<<ans+i<<'\n';
                break;
            }
        }else{
            if(mp[i]==0){
                cout<<i*2<<'\n';
                break;
            }else{
                ans=i;
            }
        }
    }
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