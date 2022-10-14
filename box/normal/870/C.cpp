// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;


#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    // 4 1
    // 9
    // 4 4 4 3
    // 6 9
    int q; cin>>q;
    while(q--){
        int n;cin>>n;
        if(n%4==0)cout<<n/4<<'\n';
        else if(n%4==1){
            if(n<9)cout<<-1<<endl;
            else cout<<(n-9)/4+1<<endl;
        }else if(n%4==2){
            if(n<6)cout<<-1<<endl;
            else cout<<(n-6)/4+1<<endl;
        }else if(n%4==3){
            if(n<15)cout<<-1<<endl;
            else cout<<(n-15)/4+2<<endl;
        }
    }
}