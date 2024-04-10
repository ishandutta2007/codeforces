#include <bits/stdc++.h>
using namespace std;
struct result_t{
    multimap<int, bool> mp_all; // false: +1, true: -1
    multimap<int, bool> mp_binary;
};
constexpr int MAXN = 300000;
pair<int,int> rs[MAXN];
vector<int> adjlist1[MAXN], adjlist2[MAXN];
int dfs1(int i,int k){
    rs[i].first=k++;
    for(int x : adjlist1[i]){
        k=dfs1(x,k);
    }
    rs[i].second=k++;
    return k;
}
void insert_binary(multimap<int, bool>& mp_binary, int left, int right) {
    auto it_left=mp_binary.lower_bound(left);
    if(it_left==mp_binary.end()||!it_left->second){
        mp_binary.insert(it_left, {left, false});
    }
    auto it_right=mp_binary.lower_bound(right);
    if(it_right==mp_binary.end()||!it_right->second){
        if (it_left==it_right){
            it_left = it_right = mp_binary.insert(it_right, {right, true});
        }
        else {
            it_right = mp_binary.insert(it_right, {right, true});
        }
    }
    mp_binary.erase(it_left, it_right);
}
result_t merge_res(result_t left, result_t right){
    multimap<int, bool> ret_all;
    if (left.mp_all.size() >= right.mp_all.size()){
        // move right into left
        left.mp_all.insert(right.mp_all.begin(), right.mp_all.end());
        ret_all=move(left.mp_all);
    }
    else {
        // move left into right
        right.mp_all.insert(left.mp_all.begin(), left.mp_all.end());
        ret_all=move(right.mp_all);
    }
    multimap<int, bool> ret_binary;
    /*cout<<"left:"<<endl;
    for(auto [i,b]: left.mp_binary) {
        cout<<i<<' '<<b<<endl;
    }
    cout<<"right:"<<endl;
    for(auto [i,b]: right.mp_binary) {
        cout<<i<<' '<<b<<endl;
    }*/
    if(left.mp_binary.size()>=right.mp_binary.size()){
        // move right into left
        auto it = right.mp_binary.begin();
        while(it!=right.mp_binary.end()){
            pair<int, bool> pr1=*it++;
            pair<int, bool> pr2=*it++;
            insert_binary(left.mp_binary, pr1.first, pr2.first);
        }
        ret_binary=move(left.mp_binary);
    }
    else {
        // move left into right
        auto it = left.mp_binary.begin();
        while(it!=left.mp_binary.end()){
            pair<int, bool> pr1=*it++;
            pair<int, bool> pr2=*it++;
            insert_binary(right.mp_binary, pr1.first, pr2.first);
        }
        ret_binary=move(right.mp_binary);
    }
    /*cout<<"merged:"<<endl;
    for(auto [i,b]: ret_binary) {
        cout<<i<<' '<<b<<endl;
    }*/
    return {move(ret_all), move(ret_binary)};
}
void amb(multimap<int, bool>& mp_binary, multimap<int, bool>& mp_all, int left, int right) {
    auto it_left=mp_binary.lower_bound(left);
    //bool overriden=false;
    if(it_left==mp_binary.end()||!it_left->second){
        mp_binary.insert(it_left, {left, false});
        mp_all.insert({left,false});
        //overriden=true;
    }
    //cout<<"  "<<it_left->first<<' '<<right<<endl;
    while (it_left!=mp_binary.end()&&it_left->first<=right){
        //cout<<' '<<it_left->first<<endl;
        mp_all.erase(mp_all.find(it_left->first));
        mp_binary.erase(it_left++);
    }
    if(it_left==mp_binary.end()||!it_left->second){
        mp_binary.insert(it_left,{right,true});
        mp_all.insert({right, true});
    }
    /*auto it_right=mp_binary.lower_bound(right);
    if(it==mp_binary.end()||!it->second){
        it_right = mp_binary.insert(it_left, {left, true});
    }
    mp_binary.erase(it_left, it_right);*/
}
result_t dfs2(int i){
    result_t res;
    for(int x : adjlist2[i]){
        res=merge_res(move(res), dfs2(x));
    }
    /*cout<<"dfs2_bin_before "<<i<<endl;
    for(auto [i,b]: res.mp_binary) {
        cout<<i<<' '<<b<<endl;
    }
    cout<<"dfs2_all_before "<<i<<endl;
    for(auto [i,b]: res.mp_all) {
        cout<<i<<' '<<b<<endl;
    }*/
    amb(res.mp_binary, res.mp_all, rs[i].first, rs[i].second);
    /*cout<<"dfs2_bin_after "<<i<<endl;
    for(auto [i,b]: res.mp_binary) {
        cout<<i<<' '<<b<<endl;
    }
    cout<<"dfs2_all_after "<<i<<endl;
    for(auto [i,b]: res.mp_all) {
        cout<<i<<' '<<b<<endl;
    }*/
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=1;i<n;++i){
            int x;
            cin>>x;
            --x;
            adjlist1[x].push_back(i);
        }
        for(int i=1;i<n;++i){
            int x;
            cin>>x;
            --x;
            adjlist2[x].push_back(i);
        }
        dfs1(0,0);
        /*for(int i=0;i<n;++i){
            cout<<rs[i].first<<' '<<rs[i].second<<endl;
        }*/
        result_t res=dfs2(0);
        int m=0;
        int best=0;
        for (pair<int, bool> pr : res.mp_all){
            if(!pr.second)++m;
            else --m;
            best=max(best,m);
        }
        cout<<best<<'\n';
        for(int i=0;i<n;++i){
            adjlist1[i].clear();
            adjlist2[i].clear();
        }
    }
}