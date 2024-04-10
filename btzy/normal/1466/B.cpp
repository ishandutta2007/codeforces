#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        int distinct=0;
        int last=0;
        for(int x:v){
            if(x<last)continue;
            if(x==last){
                ++last;
                ++distinct;
                continue;
            }
            last=x;
            ++distinct;
        }
        cout<<distinct<<endl;
    }
}