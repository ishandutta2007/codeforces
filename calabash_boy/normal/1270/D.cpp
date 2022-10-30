#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
map<int,int> mp;
int ask(vector<int> vec){
    cout<<"?";
    for (int x : vec){
        cout<<" "<<x;
    }
    cout<<endl;
    int x,y;
    cin>>x>>y;
    return y;
}
int main(){
    int n,k;
    cin>>n>>k;

    for (int o=1;o<=k + 1;o ++){
        vector<int> tmp(0);
        for (int i = 1;i <= k + 1;i ++){
            if (i != o)tmp.push_back(i);
        }
        int val = ask(tmp);
        mp[val] ++;
    }
    cout<<"! "<<mp.rbegin()->second<<endl;
    return 0;
}