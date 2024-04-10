#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int bit[(int)2e5+1];
pii am[(int)2e5+1];
int n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
int query(int loc){
    int sum=0;
    for(;loc>0;loc-=loc&-loc)sum+=bit[loc];
    return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        cin>>n;
        string a;
        cin>>a;
        int cur=0;
        int side=-1;
        for(int i=sz(a)-1;i>=0;i--){
            int te=(a[i]=='<'?0:1);
            if(te==side)cur++;
            else cur=1,side=te;
            am[i]={cur,side};
        }
        set<int> nums;
        for(int i=1;i<=n;i++)update(i,1),nums.insert(i);
        int last=-1;
        for(int i=0;i<sz(a);i++){
            int lo=1,hi=n;
            if(last==-1) {
                lo=1,hi=n;
            }
            else{
                if(a[i-1]=='>'){
                    lo=1,hi=last-1;
                }
                else{
                    lo=last+1,hi=n;
                }
            }
            if(am[i].second==0){
                while(lo!=hi) {
                    int mid = (lo + hi) / 2+1;
                        if (query(n) - query(mid) >= am[i].first)lo = mid;
                        else hi=mid-1;
                }
                auto ele=nums.upper_bound(lo);
                ele--;
                printf("%d ",*ele);
                last=*ele;
                update(*ele,-1);
                nums.erase(ele);
            }
            else{
                auto ele=nums.upper_bound(hi);
                ele--;
                printf("%d ",*ele);
                last=*ele;
                update(*ele,-1);
                nums.erase(ele);
            }
        }
        auto ele=nums.begin();
        printf("%d\n",*ele);
        update(*ele,-1);
        nums.erase(ele);
        for(int i=1;i<=n;i++)update(i,1),nums.insert(i);
        last=-1;
        for(int i=0;i<sz(a);i++){
            int lo=1,hi=n;
            if(last==-1) {
                lo=1,hi=n;
            }
            else{
                if(a[i-1]=='>'){
                    lo=1,hi=last-1;
                }
                else{
                    lo=last+1,hi=n;
                }
            }
            if(am[i].second==1){
                while(lo!=hi) {
                    int mid = (lo + hi) / 2;
                    if (query(mid-1) >= am[i].first)hi = mid;
                    else lo=mid+1;
                }
                ele=nums.lower_bound(lo);
                printf("%d ",*ele);
                last=*ele;
                update(*ele,-1);
                nums.erase(ele);
            }
            else{
                ele=nums.lower_bound(lo);
                printf("%d ",*ele);
                last=*ele;
                update(*ele,-1);
                nums.erase(ele);
            }
        }
        ele=nums.begin();
        printf("%d\n",*ele);
        update(*ele,-1);
        nums.erase(ele);
    }
    return 0;
}