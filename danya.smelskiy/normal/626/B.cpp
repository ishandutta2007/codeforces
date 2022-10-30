#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool used[305][305][305];
int l,r;
struct st{
    int a,b,c;
};
st q[8000005];
int a,b,c;
inline void add(int x,int y,int z){
    if (used[x][y][z]) return;
    used[x][y][z]=true;
    ++r;
    st t;
    t.a=x; t.b=y; t.c=z;
    q[r]=t;
}
int main(){
    cin>>n>>s;
    for (int i=0;i<s.size();++i)
        if (s[i]=='G') ++a;
        else if (s[i]=='R') ++b;
        else ++c;
    add(a,b,c);
    l=1;
    while (l<=r) {
        a=q[l].a; b=q[l].b; c=q[l].c;
        if (a && b) add(a-1,b-1,c+1);
        if (a && c) add(a-1,b+1,c-1);
        if (b && c) add(a+1,b-1,c-1);
        if (a>1) add(a-1,b,c);
        if (b>1) add(a,b-1,c);
        if (c>1) add(a,b,c-1);
        ++l;
    }
    if (used[0][0][1]) cout<<"B";
    if (used[1][0][0]) cout<<"G";
    if (used[0][1][0]) cout<<"R";
}