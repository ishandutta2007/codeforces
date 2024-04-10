#include <bits/stdc++.h>
using namespace std;


int n;
string nw;
int res1,res2;
int f;
inline int ask(string x){
    cout<<"? "<<x<<endl;
    int res;
    cin>>res;
    return res;
}
inline void solve(int l,int r){
    if (l==r) {
        if (f==1) cout<<"! "<<l<<" "<<1<<endl;
        else cout<<"! "<<1<<" "<<l<<endl;
        exit(0);
    }
    int mid=(l+r)>>1;
    string nw2=nw;
    for (int i=l;i<=mid;++i)
        nw2[i-1]=char('0'+f);
    int res3=ask(nw2);
    if (res3!=res2-(mid-l+1)) solve(l,mid);
    else solve(mid+1,r);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    nw="";
    for (int i=1;i<=n;++i)
        nw+="0";
    res1=ask(nw);
    nw[0]='1';
    res2=ask(nw);
    if (res2<res1){
        f=1;
    }
    else { res2=n-1-res1; f=0;}
    nw="";
    nw+=char(f+'0');
    for (int i=2;i<=n;++i)
        nw+=char('0'+1-f);
    solve(2,n);
}