#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli arr[(int)2e5+1];
lli bit[(int)1e6+1];
vector<lli> ree;
void update(int loc){
    for(;loc<=sz(ree);loc+=loc&-loc)bit[loc]++;
}
lli query(int loc){
    lli ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli a;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i]-=a;
    }

    for(int i=0;i<n;i++){
        ree.push_back(arr[i]);
        ree.push_back(-arr[i]);
    }
    sort(ree.begin(),ree.end());
    ree.erase(unique(ree.begin(),ree.end()),ree.end());
    lli ans=0;
    for(int i=0;i<n;i++){
        ans+=query(sz(ree))-query((lower_bound(ree.begin(),ree.end(),-arr[i])-ree.begin())+1);
        update((lower_bound(ree.begin(),ree.end(),arr[i])-ree.begin())+1);
    }
    printf("%lli\n",ans);
    return 0;
}