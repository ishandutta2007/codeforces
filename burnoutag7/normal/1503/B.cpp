#include<bits/stdc++.h>
using namespace std;

int n,a[105][105];
set<pair<int,int>> s[2];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        s[i+j&1].emplace(i,j);
    }
    for(int step=0;step<n*n;step++){
        int ban;
        cin>>ban;
        if(ban==3){
            if(s[0].empty()){
                cout<<2<<' '<<s[1].begin()->first<<' '<<s[1].begin()->second<<endl;
                s[1].erase(s[1].begin());
            }else{
                cout<<1<<' '<<s[0].begin()->first<<' '<<s[0].begin()->second<<endl;
                s[0].erase(s[0].begin());
            }
        }else{
            if(s[ban-1^1].empty()){
                cout<<3<<' '<<s[ban-1].begin()->first<<' '<<s[ban-1].begin()->second<<endl;
                s[ban-1].erase(s[ban-1].begin());
            }else{
                cout<<(ban-1^1)+1<<' '<<s[ban-1^1].begin()->first<<' '<<s[ban-1^1].begin()->second<<endl;
                s[ban-1^1].erase(s[ban-1^1].begin());
            }
        }
    }

    return 0;
}