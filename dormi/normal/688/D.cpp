#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<int> has;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a;
    int tek=k;
    for(int i=2;i*i<=tek;i++){
        int cur=1;
        while(tek%i==0){
            cur*=i;
            tek/=i;
        }
        if(cur>1)has.insert(cur);
    }
    if(tek>1)has.insert(tek);
    for(int i=0;i<n;i++){
        cin>>a;
        vector<int> toer;
        for(int x:has){
            if(a%x==0){
                toer.push_back(x);
            }
        }
        for(int x:toer)has.erase(x);
    }
    if(sz(has)==0){
        printf("Yes\n");
    }
    else printf("No\n");
    return 0;
}