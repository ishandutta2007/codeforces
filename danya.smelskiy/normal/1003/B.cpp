#include <bits/stdc++.h>
using namespace std;


int a,b,x;
int c[1005];
int y;
char c1,c2;




int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>x;
    ++x;
    c1='0',c2='1';
    if (a<b) {
        swap(c1,c2);
        swap(a,b);
    }
    y=(x+1)/2;
    a-=y;
    b-=x/2;
    for (int i=1;i<=x;++i)
        c[i]=1;
    c[1]+=a;
    c[2]+=b;
    for (int i=1;i<=x;++i) {
        for (int j=1;j<=c[i];++j)
            if (i&1) cout<<c1;
            else cout<<c2;
    }
}