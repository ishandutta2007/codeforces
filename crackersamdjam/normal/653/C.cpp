#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=150003;
int arr[MAXN];
set<pii> used;
int n;
bool valid(int loc){
    if(loc%2){
        if(arr[loc]<arr[loc-1]&&arr[loc]<arr[loc+1])return true;
        return false;
    }
    else{
        if(arr[loc]>(loc-1>0?arr[loc-1]:0)&&arr[loc]>(loc+1<=n?arr[loc+1]:0))return true;
        return false;
    }
}
bool work(){
    for(int i=1;i<=n;i++){
        if(i%2){
            if(arr[i-1]<=arr[i]){
                return false;
            }
        }
        else if(arr[i-1]>=arr[i])return false;
    }
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    vector<int> bad;
    arr[n+1]=INT_MAX;
    arr[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(i%2){
            if(arr[i-1]<=arr[i]){
                bad.push_back(i);
            }
        }
        else if(arr[i-1]>=arr[i])bad.push_back(i);
    }
//    if(!sz(bad)){
//        lli ans=0;
//        for(int i=1;i<=n;i++){
//            if(i%2){
//                int mi=min(arr[i-1],arr[i+1])-1;
//                if(mi>=arr[i]-1)ans+=query(1,mi)-query(1,arr[i]-1);
//                ans+=query(0,min(mi,arr[i]));
//            }
//            else{
//                int ma=max((i-1>0?arr[i-1]:0),(i+1<=n?arr[i+1]:0))+1;
//                if(arr[i]>=ma-1)ans+=query(0,arr[i])-query(0,ma-1);
//                ans+=query(1,150000)-query(1,max(arr[i]-1,ma-1));
//            }
//            update(i%2,arr[i]);
//        }
//        printf("%lli\n",ans);
//    }
//    else{
    lli ans=0;
    sort(bad.begin(),bad.end());
    for(int i=1;i<=n;i++)used.insert({i,i});
    if(sz(bad)==1){
        for(int i=1;i<=n;i++){
            if(!used.count({i,bad[0]})) {
                used.insert({i,bad[0]});
                used.insert({bad[0],i});
                swap(arr[i], arr[bad[0]]);
                if (valid(i) && valid(bad[0]))ans += 1;
                swap(arr[i], arr[bad[0]]);
            }
            if(!used.count({i,bad[0]-1})) {
                used.insert({i, bad[0]-1});
                used.insert({bad[0]-1, i});
                swap(arr[i], arr[bad[0] - 1]);
                if (valid(i) && valid(bad[0] - 1))ans += 1;
                swap(arr[i], arr[bad[0] - 1]);
            }
        }
    }
    else if(sz(bad)==2){
        if(abs(bad[0]-bad[1])==1){
            for(int i=1;i<=n;i++){
                if(!used.count({i,bad[0]})) {
                    used.insert({i, bad[0]});
                    used.insert({bad[0], i});
                    swap(arr[i], arr[bad[0]]);
                    if (valid(i) && valid(bad[0]))ans += 1;
                    swap(arr[i], arr[bad[0]]);
                }
            }
        }
        else{
            if(!used.count({bad[1],bad[0]})) {
                used.insert({bad[1], bad[0]});
                used.insert({bad[0], bad[1]});
                swap(arr[bad[0]], arr[bad[1]]);
                if (work())ans += 1;
                swap(arr[bad[0]], arr[bad[1]]);
            }
            if(!used.count({bad[1],bad[0]-1})) {
                used.insert({bad[1], bad[0]-1});
                used.insert({bad[0]-1, bad[1]});
                swap(arr[bad[0] - 1], arr[bad[1]]);
                if (work())ans += 1;
                swap(arr[bad[0] - 1], arr[bad[1]]);
            }
            if(!used.count({bad[1]-1,bad[0]})) {
                used.insert({bad[1]-1, bad[0]});
                used.insert({bad[0], bad[1]-1});
                swap(arr[bad[0]], arr[bad[1] - 1]);
                if (work())ans += 1;
                swap(arr[bad[0]], arr[bad[1] - 1]);
            }
            if(!used.count({bad[1]-1,bad[0]-1})) {
                used.insert({bad[1]-1, bad[0]-1});
                used.insert({bad[0]-1, bad[1]-1});
                swap(arr[bad[0] - 1], arr[bad[1] - 1]);
                if (work())ans += 1;
                swap(arr[bad[0] - 1], arr[bad[1] - 1]);
            }
        }
    }
    else if(sz(bad)==3){
        if(bad[1]==bad[0]+1){
            if(!used.count({bad[2],bad[0]})) {
                used.insert({bad[2], bad[0]});
                used.insert({bad[0], bad[2]});
                swap(arr[bad[0]], arr[bad[2]]);
                if (work())ans += 1;
                swap(arr[bad[0]], arr[bad[2]]);
            }
            if(!used.count({bad[2]-1,bad[0]})) {
                used.insert({bad[2]-1, bad[0]});
                used.insert({bad[0], bad[2]-1});
                swap(arr[bad[0]], arr[bad[2] - 1]);
                if (work())ans += 1;
                swap(arr[bad[0]], arr[bad[2] - 1]);
            }
        }
        else if(bad[2]==bad[1]+1){
            if(!used.count({bad[1],bad[0]})) {
                used.insert({bad[1], bad[0]});
                used.insert({bad[0], bad[1]});
                swap(arr[bad[0]], arr[bad[1]]);
                if (work())ans += 1;
                swap(arr[bad[0]], arr[bad[1]]);
            }
            if(!used.count({bad[1],bad[0]-1})) {
                used.insert({bad[1], bad[0]-1});
                used.insert({bad[0]-1, bad[1]});
                swap(arr[bad[0] - 1], arr[bad[1]]);
                if (work())ans += 1;
                swap(arr[bad[0] - 1], arr[bad[1]]);
            }
        }
    }
    else{
        if(bad[1]==bad[0]+1&&bad[3]==bad[2]+1){
            if(!used.count({bad[2],bad[0]})) {
                used.insert({bad[2], bad[0]});
                used.insert({bad[0], bad[2]});
                swap(arr[bad[0]], arr[bad[2]]);
                if (work())ans += 1;
                swap(arr[bad[0]], arr[bad[2]]);
            }
        }
    }
    printf("%lli\n",ans);
    //}
    return 0;
}