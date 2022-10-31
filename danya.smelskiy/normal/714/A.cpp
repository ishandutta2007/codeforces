#include<bits/stdc++.h>
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define sqr(a) ((a)*(a))

using namespace std;
long long ans,l,r,x,y,n;
int main(){
    cin>>l>>r>>x>>y>>n;
    if (y<l || x>r){
        cout<<"0";
        return 0;
    }
    if (x<=l && y>=r){
        ans=(r-l+1);
    } else
    if (x>=l && y<=r) {
        ans=(y-x+1);
    }else
    if (x<=r && x>=l && y>=r) {
        ans=(r-x+1);
    }else
    if (y<=r && y>=l && x<=l) {
        ans=(y-l+1);
    }
    if (n<=r && n>=x  && n<=y && n>=l && ans>0) --ans;
    cout<<ans;
}