#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[(int)2e5+1];
int day[(int)2e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,d;
    cin>>n>>m>>d;
    set<pii> st;
    for(int i=0;i<n;i++){
       cin>>arr[i];
       st.insert({arr[i],i});
    }
    int cur=1;
    while(sz(st)){
        auto c = st.begin();
        while(c!=st.end()) {
            day[c->second] = cur;
            auto old=c;
            c = st.lower_bound({c->first + d + 1, 0});
            st.erase(old);
        }
        cur++;
    }
    printf("%d\n",cur-1);
    for(int i=0;i<n;i++)printf("%d ",day[i]);
    return 0;
}