#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
struct item{
    int id, savetime, destructiontime, value;
};
struct state{
    int bestval, besttime;
    vector<int> items;
};
int n;
item arr[101];
state dp[101][2001];
int itemidx[101][2001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        arr[i].id=i;
        cin>>arr[i].savetime>>arr[i].destructiontime>>arr[i].value;
    }
    sort(arr+1,arr+n+1,[](const item& a, const item& b){
        return a.destructiontime<b.destructiontime;
    });
    for(int i=0;i<=2000;++i){
        dp[0][i]={0,0,{}};
    }
    for(int idx=1;idx<=n;++idx){
        for(int t=0;t<=2000;++t){
            if(t>0)dp[idx][t]=dp[idx][t-1];
            else dp[idx][t]={0,0,{}};
            if(dp[idx-1][t].bestval>dp[idx][t].bestval){
                dp[idx][t]=dp[idx-1][t];
            }
            if(t>=arr[idx].savetime&&t<arr[idx].destructiontime&&dp[idx-1][t-arr[idx].savetime].bestval+arr[idx].value>dp[idx][t].bestval){
                dp[idx][t]=dp[idx-1][t-arr[idx].savetime];
                dp[idx][t].bestval+=arr[idx].value;
                dp[idx][t].besttime+=arr[idx].savetime;
                dp[idx][t].items.emplace_back(idx);
            }
        }
    }
    state beststate=dp[n][2000];
    cout<<accumulate(beststate.items.begin(),beststate.items.end(),0,[](int prev,int idx){
        return prev+arr[idx].value;
    })<<endl;
    cout<<beststate.items.size()<<endl;
    for(int idx:beststate.items){
        cout<<arr[idx].id<<' ';
    }
    cout<<endl;
}