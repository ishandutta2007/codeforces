#include <bits/stdc++.h>
using namespace std;

string s;
long long x,a[100];
int sz=3;
inline int getcount(long long x){
    int c=0;
    while (x){
        c+=x%10;
        x/=10;
    }
    return c;
}
inline bool cmp(long long x,long long y){
    if (getcount(x)!=getcount(y)) return getcount(x)>getcount(y);
    return x>y;
}
int main(){
    cin>>s;
    if (s.size()==1) {
        cout<<s;
        return 0;
    }
    for (int i=1;i<=s.size();++i)
        x=x*10+(s[i-1]-'0');
    a[1]=x;
    for (int i=2;i<=s.size();++i)
        a[2]=a[2]*10+9;
    a[3]=s[0]-'0'-1;
    for (int i=2;i<=s.size();++i)
        a[3]=a[3]*10+9;
    for (int i=s.size();i>0;--i){
        long long r=0;
        if (s[i-1]=='0') continue;
        for (int j=1;j<i;++j)
            r=r*10+(s[j-1]-'0');
        r=r*10+(s[i-1]-'0'-1);
        for (int j=i+1;j<=s.size();++j)
            r=r*10+9;
        ++sz;
        a[sz]=r;
    }
    sort(a+1,a+sz+1,cmp);
    cout<<a[1];
}