#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+100;
typedef long long LL;
int x,d;
int val[40];
vector<pair<LL,int> >ans;
int n;
int main(){
    cin>>x>>d;
    for (int i=0;i<=31;i++){
        LL temp = 1LL<<i;
        val[i] = temp-1;
    }
    LL now =1;
    while (x){
        int k = lower_bound(val,val+32,x)-val;
        if (val[k]>x)k--;
        n+=k;
        ans.push_back(make_pair(now,k));
        x-=val[k];
        now+=d;
    }
    cout<<n<<endl;
    for (auto temp:ans){
        for (int i=0;i<temp.second;i++){
            cout<<temp.first<<" ";
        }
    }
    return 0;
}