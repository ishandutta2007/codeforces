#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
using namespace std;
typedef long long ll;
pair<int,int> amount[300000];
int n,x1,x2;
template <bool Swapped>
bool solve(int a1, int a2){
    int curr=0;
    for(;curr<n;++curr){
        if(a1<=static_cast<ll>(amount[curr].first)*(curr+1)){
            break;
        }
    }
    if(curr==n)return false;
    int curr2=curr;
    for(;curr2<n;++curr2){
        if(a2<=static_cast<ll>(amount[curr2].first)*(curr2-curr)){
            break;
        }
    }
    if(curr2==n)return false;
    //cout<<"~"<<curr<<' '<<curr2<<endl;
    //cout<<amount[0].first<<amount[1].first<<amount[2].first<<amount[3].first<<endl;
    cout<<"Yes\n";
    if(Swapped){
        cout<<curr2-curr<<' '<<(curr+1)<<'\n';
        bool fl=false;
        for(int i=curr+1;i<=curr2;++i){
            if(fl)cout<<' ';
            fl=true;
            cout<<amount[i].second;
        }
        cout<<'\n';
        fl=false;
        for(int i=0;i<=curr;++i){
            if(fl)cout<<' ';
            fl=true;
            cout<<amount[i].second;
        }
        cout<<'\n';
    }
    else{
        cout<<(curr+1)<<' '<<curr2-curr<<'\n';
        bool fl=false;
        for(int i=0;i<=curr;++i){
            if(fl)cout<<' ';
            fl=true;
            cout<<amount[i].second;
        }
        cout<<'\n';
        fl=false;
        for(int i=curr+1;i<=curr2;++i){
            if(fl)cout<<' ';
            fl=true;
            cout<<amount[i].second;
        }
        cout<<'\n';
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    cin>>n>>x1>>x2;
    for(int i=0;i<n;++i){
        cin>>amount[i].first;
        amount[i].second=i+1;
    }
    sort(amount,amount+n,[](const pair<int,int>& x,const pair<int,int>& y){
        return x.first>y.first;
    });
    if(solve<false>(x1,x2))return 0;
    if(solve<true>(x2,x1))return 0;
    cout<<"No\n";
    return 0;
}