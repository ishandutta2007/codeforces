#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,l,r,a;
        cin>>n>>l>>r;
        for(int i=1;i<=n;i++)cnt[i]=0;
        vector<int> left,right;
        for(int i=0;i<l;i++){
            cin>>a;
            left.push_back(a);
        }
        for(int i=0;i<r;i++){
            cin>>a;
            right.push_back(a);
        }
        if(l>r){
            swap(l,r),swap(left,right);
        }
        for(int i=0;i<l;i++)cnt[left[i]]++;
        vector<int> rightunmatched;
        vector<int> leftunmatched;
        for(int i=0;i<r;i++){
            if(cnt[right[i]]==0)rightunmatched.push_back(right[i]);
            else{
                cnt[right[i]]--;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<cnt[i];j++)leftunmatched.push_back(i);
            cnt[i]=0;
        }
        int leftcnt=l;
        int cost=0;
        for(auto x:rightunmatched){
            if(cnt[x]==0||leftcnt==n/2){
                cnt[x]++;
            }
            else{
                cnt[x]--;
                cost++;
                leftcnt++;
            }
        }
        cost+=n/2-leftcnt+sz(leftunmatched)+n/2-leftcnt;
        printf("%d\n",cost);
    }
    return 0;
}