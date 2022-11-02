#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        vector<int> ctx;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            if(x==1){
                ctx.push_back(x);
            }
            else {
                while(ctx.back()+1!=x)ctx.pop_back();
                ctx.back()=x;
            }
            cout<<ctx.front();
            for(auto it=ctx.begin()+1;it!=ctx.end();++it){
                cout<<'.'<<*it;
            }
            cout<<'\n';
        }
    }
}