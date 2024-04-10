#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
// first id, second time
//set<pair<int,int> > nums;
// id[time] = id;
map<int,int> id;
set<int> nums;
int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        int myid;
        cin>>myid;
        if (nums.count(myid))continue;
        if (nums.size() < k){
            nums.insert(myid);
            id[i] = myid;
        }else{
            auto pr = *id.begin();
//            int previd = pr.second;
            id.erase(pr.first);
            nums.erase(pr.second);
            id[i] = myid;
            nums.insert(myid);
        }
    }
    vector<int> ans(0);
    for (auto pr : id){
        ans.push_back(pr.second);
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}