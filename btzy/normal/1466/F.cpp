#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=500000;
constexpr uint64_t MOD=1000000007;
template <typename T>
class small_set{
public:
    small_set():sz(0){}
    void insert(T x){
        if(sz==0){
            arr[0]=move(x);
            sz=1;
        }
        else{
            if(arr[0]<x){
                arr[1]=move(x);
            }
            else{
                arr[1]=arr[0];
                arr[0]=move(x);
            }
            sz=2;
        }
    }
    void erase(T x) {
        if(sz==1){
            sz=0;
        }
        else{
            if(arr[0]==x){
                arr[0]=arr[1];
            }
            sz=1;
        }
    }
    void clear() { sz=0; }
    T* find(T x) {
        if(sz>0&&arr[0]==x)return &arr[0];
        if(sz>1&&arr[1]==x)return &arr[1];
        return end();
    }
    T* begin() { return arr; }
    T* end() { return arr+sz; }
    void erase(T* ptr) {
        if(sz==2&&ptr==arr)arr[0]=arr[1];
        --sz;
    }
    bool empty() const noexcept { return sz==0; }
private:
    T arr[2];
    size_t sz;
};
small_set<int> vecs[MAXN];
set<int> regs[MAXN];
uint64_t expmod(unsigned val){
    uint64_t ans=1;
    for(unsigned i=0;i!=val;++i){
        ans<<=1;
        ans%=MOD;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        int len;
        cin>>len;
        for(int j=0;j<len;++j){
            int tmp;
            cin>>tmp;
            --tmp;
            vecs[i].insert(tmp);
            regs[tmp].insert(i);
        }
    }
    vector<int> selectedidx;
    for(int i=0;i<n;++i){
        if(vecs[i].empty())continue;
        selectedidx.push_back(i);
        auto it=vecs[i].begin();
        int dim=*it;
        ++it;
        if(it==vecs[i].end()){
            // no migration needed
            regs[dim].erase(i);
            for(int j:regs[dim]){
                vecs[j].erase(dim);
            }
            regs[dim].clear();
            vecs[i].clear();
        }
        else{
            int migdim=*it;
            if(regs[migdim].size()<regs[dim].size()){
                swap(dim,migdim);
            }
            regs[dim].erase(i);
            regs[migdim].erase(i);
            for(int j:regs[dim]){
                vecs[j].erase(dim);
                auto itvec=vecs[j].find(migdim);
                if(itvec!=vecs[j].end()){
                    vecs[j].erase(itvec);
                    regs[migdim].erase(j);
                }
                else{
                    vecs[j].insert(migdim);
                    regs[migdim].insert(j);
                }
            }
            regs[dim].clear();
            vecs[i].clear();
        }
    }
    cout<<expmod(selectedidx.size())<<' '<<selectedidx.size()<<'\n';
    bool first=false;
    for(int x:selectedidx){
        if(first)cout<<' ';
        first=true;
        cout<<x+1;
    }
    cout<<'\n';
}