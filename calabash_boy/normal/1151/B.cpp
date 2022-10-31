#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
int mat[maxn][maxn];
int n,m;
vector<int> v0,v1,va;
int find_idx(int row_id,int bit,int tar){
    for (int i=0;i<m;i++){
        if ((mat[row_id][i] & bit) == tar){
            return i+1;
        }
    }
    assert(0);
}
int ans[maxn];
void output(){
    puts("TAK");
    for (int i=0;i<n;i++){
        printf("%d ",max(1,ans[i]));
    }
    puts("");
}
bool check(int bit){
    v0.clear();
    v1.clear();
    va.clear();
    for (int i=0;i<n;i++){
        bool has0 = false,has1 = false;
        for (int j=0;j<m;j++){
            if (mat[i][j] & bit){
                has1 = true;
            }else{
                has0 = true;
            }
        }
        if (has1 && has0)va.push_back(i);
        else if (has1)v1.push_back(i);
        else if (has0)v0.push_back(i);
        else assert(0);
    }
    int cnt1 = v1.size();
    //cerr<<v1.size()<<" "<<v0.size()<<" "<<va.size()<<endl;
    if ((cnt1 & 1) || va.size()){
        if (cnt1&1){
            for (int idx : va){
                ans[idx] = find_idx(idx,bit,0);
            }
        }else{
            ans[va.back()] = find_idx(va.back(),bit,bit);
            va.pop_back();
            for (int idx : va){
                ans[idx] = find_idx(idx,bit,0);
            }
        }
        output();
        cerr<<bit<<endl;
        return true;
    }

    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for (int bit = 1;bit <1024;bit <<= 1){
        if (check(bit))return 0;
    }
    puts("NIE");
    return 0;
}