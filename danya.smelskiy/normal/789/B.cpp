#include <bits/stdc++.h>
using namespace std;
long long b,q,l,m,a[100005];
long long ans,last;
map<long long,bool> used;

int main(){
    cin>>b>>q>>l>>m;
    for(int i=1;i<=m;++i){
        cin>>a[i];
        used[a[i]]=true;
    }
    long long last=b;
    int kol=0;
    while (abs(last)<=l) {
        if (used[last]==false) {
            ++ans;
        }
        ++kol;
        if (last==0 && used[last]==false){
            cout<<"inf";
            return 0;
        }
        if (last==0) break;
        if (abs(q)==1 && used[last]==false) {
            cout<<"inf";
            return 0;
        } else if (q==1) break;
        if (q==-1 && kol>55) break;
        last*=q;
    }
    cout<<ans;
}