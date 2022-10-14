#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
bool query(int i){//does not contain the stationary point
    if(i==0)return true;
    printf("? %d %d\n",1,i);
    int a;
    int outside=0;
    for(int j=1;j<=i;j++){
        cin>>a;
        if(a==-1){
            exit(0);
        }
        if(a>i)outside++;
    }
    if(outside%2==i%2)return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int lo=0,hi=n-1;
        while(lo!=hi){
            int mid=(lo+hi+1)/2;
            if(query(mid))lo=mid;
            else hi=mid-1;
        }
        printf("! %d\n",lo+1);
    }
    return 0;
}