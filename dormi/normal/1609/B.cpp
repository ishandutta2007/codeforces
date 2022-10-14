#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    string a;
    cin>>a;
    int count=0;
    for(int i=0;i+2<n;i++){
        if(a[i]=='a'&&a[i+1]=='b'&&a[i+2]=='c'){
            count++;
        }
    }
    int loc;
    char c;
    auto check=[&](int ind){
        int ans=0;
        for(int i=-2;i<=0;i++){
            if(i+ind<0||i+ind+2>=n)continue;
            if(a[i+ind]=='a'&&a[i+1+ind]=='b'&&a[i+2+ind]=='c'){
                ans++;
            }
        }
        return ans;
    };
    while(q--){
        cin>>loc>>c;
        loc--;
        count-=check(loc);
        a[loc]=c;
        count+=check(loc);
        printf("%d\n",count);
    }
    return 0;
}