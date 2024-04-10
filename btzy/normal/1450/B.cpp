#include <bits/stdc++.h>
using namespace std;
int distance(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> arr;
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            arr.emplace_back(x,y);
        }
        bool same = true;
        for (int i=1;i<n;++i){
            if(arr[0]!=arr[i]){
                same=false;
                break;
            }
        }
        if(same){
            cout<<"0\n";
            continue;
        }
        int i,j;
        for(i=0;i<n;++i){
            for (j=0;j<n;++j){
                if(distance(arr[i],arr[j])>k){
                    break;
                }
            }
            if(j==n){
                break;
            }
        }
        if(i<n){
            cout<<"1\n";
            continue;
        }
        cout<<"-1\n";
    }
}