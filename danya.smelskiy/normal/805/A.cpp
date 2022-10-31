#include <bits/stdc++.h>
using namespace std;

long long l,r;
long long maxkol,maxans;
inline void chek(int x){
    int kol=r/x-(l-1)/x;
    if (kol>maxkol) {
        maxkol=kol;
        maxans=x;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>l>>r;
    maxans=l;
    for (int i=2;i<=1e5;++i) {
        chek(i);
    }
    cout<<maxans;
}