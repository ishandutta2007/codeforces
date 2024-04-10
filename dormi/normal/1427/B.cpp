#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string a;
        cin>>a;
        int score=0;
        vector<int> gaps;
        int lastwin=-1;
        int front=0;
        for(int i=0;i<n;i++){
            if(a[i]=='W'){
                if(lastwin!=-1&&lastwin==i-1){
                    score+=2;
                }
                else score+=1;
                if(lastwin==-1)front=i;
                else if(i-lastwin-1>0)gaps.push_back(i-lastwin-1);
                lastwin=i;
            }
        }
        int back=n-lastwin-1;
        sort(gaps.begin(),gaps.end());
        for(auto x:gaps){
            if(k>=x){
                k-=x;
                score+=2*x+1;
            }
            else{
                score+=2*k;
                k=0;
            }
        }
        if(lastwin==-1){
            score+=max(0,2*k-1);
        }
        else{
            score+=2*min(k,front);
            k-=min(k,front);
            score += 2 * min(k, back);
            k -= min(k, back);
        }
        printf("%d\n",score);
    }
    return 0;
}