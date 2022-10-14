#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e3+1;
int arr[MAXN];
vector<int> matrix[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=1;j<i;j++){
            if(arr[j]>arr[i]){
                matrix[i].push_back(j);
            }
        }
    }
    vector<pii> order;
    for(int i=n;i>=1;i--){
        sort(matrix[i].begin(), matrix[i].end(), [&](auto &lhs, auto &rhs) {
            if(arr[lhs]==arr[rhs])return lhs<rhs;
            return arr[lhs] < arr[rhs];
        });
    }
    for(int i=n;i>=1;i--){
        if(sz(matrix[i])) {
            if (arr[matrix[i].back()]<arr[i]){
                printf("-1\n");
                return 0;
            }
            for(int j=0;j<sz(matrix[i]);j++){
                order.push_back({matrix[i][j],i});
                swap(arr[matrix[i][j]],arr[i]);
            }
        }
    }
    if(!is_sorted(arr+1,arr+n+1))printf("-1\n");
    else{
        printf("%d\n",sz(order));
        for(auto x:order)printf("%d %d\n",x.first,x.second);
    }
//    for(auto x:inversions){
//        uni(x.first,x.second);
//    }
//    for(int i=1;i<=n;i++){
//        if(!done[i]&&sz(matrix[i])==dsu[find(i)].second-1){
//
//        }
//    }
//    for(int i=1;i<=n;i++){
//        if(!done[i]){
//            printf("-1\n");
//            return 0;
//        }
//    }
    return 0;
}