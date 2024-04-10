#include <bits/stdc++.h>
using namespace std;


int a,b,c,d;
string s;

inline int get(int x) {
    for (int i=2;;++i) {
        int y=i*(i-1)/2;
        if (y>x) return -1;
        if (y==x) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>d;
    int x=get(a);
    int y=get(d);
    if (a+b+c+d==0) {
        cout<<"0";
        return 0;
    }
    if (x==-1 && !b && !c && y!=-1) {
        for (int i=1;i<=y;++i)
            cout<<"1";
        return 0;
    }
    if (x!=-1 && !b && !c && y==-1){
        for (int i=1;i<=x;++i)
            cout<<"0";
        return 0;
    }
    if (x==-1) x=1;
    if (y==-1) y=1;
    if (x*y!=b+c) {
        cout<<"Impossible";
        return 0;
    }
    for (int i=1;i<=x;++i)
        s+="0";
    for (int i=1;i<=y;++i)
        s+="1";
    for (int i=x+1;i<=x+y && c;++i) {
        if (c>=x) {
            swap(s[i-x-1],s[i-1]);
            c-=x;
            continue;
        }
        swap(s[i-c-1],s[i-1]);
        break;
    }
    cout<<s;
}