#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<lli,vector<lli>> prices;
lli am[(int)2e5+1];
multiset<lli> cur;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>am[i];
    }
    lli in;
    for(int i=0;i<n;i++){
        cin>>in;
        prices[am[i]].push_back(in);
    }
    int last=0;
    lli ans=0;
    lli sum=0;
    for(auto x:prices){
        int diff=x.first-last;
        lli te=diff;
        lli days=0;
        while(diff--&&sz(cur)){
            ans+=*cur.rbegin()*days;
            sum-=*cur.rbegin();
            cur.erase(prev(cur.end(),1));
            days++;
        }
        ans+=sum*te;
        last=x.first;
        for(lli y:x.second){
            cur.insert(y);
            sum+=y;
        }
    }
    lli days=0;
    while(sz(cur)){
        ans+=*cur.rbegin()*days;
        cur.erase(prev(cur.end(),1));
        days++;
    }
    printf("%lli\n",ans);
    return 0;
}