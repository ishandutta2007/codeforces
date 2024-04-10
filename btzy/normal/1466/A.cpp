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
        vector<int> v,w;
        for(int i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                w.push_back(v[j]-v[i]);
            }
        }
        sort(w.begin(),w.end());
        w.erase(unique(w.begin(),w.end()),w.end());
        cout<<w.size()<<endl;
    }
}