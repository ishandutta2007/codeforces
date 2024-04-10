#include <bits/stdc++.h>
using namespace std;
string s,ss;
int a[1000005];
bool used[1000005];


inline bool chek(int x){
    if (s.size()-x<ss.size()) return false;
    for (int i=1;i<=s.size();++i)
        used[i]=true;
    for (int i=1;i<=x;++i)
        used[a[i]]=false;
    int last=1;
    for (int i=1;i<=s.size();++i){
        if (used[i] && s[i-1]==ss[last-1]) {
            ++last;
            if (last==ss.size()+1) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>ss;
    for (int i=1;i<=s.size();++i){
        cin>>a[i];
    }
    int l=0;
    int r=s.size();
    while (l<r-1) {
        int mid=(l+r)/2;
        if (chek(mid)) l=mid;
        else r=mid;
    }
    if (chek(r)) l=r;
    cout<<l;
}