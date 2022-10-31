#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a[5];
int b[5];
int x;

int main(){
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;++i) {
        if (s[i-1]=='r') {
            if (i%2==1) ++a[1];
            else ++a[2];
        } else {
            if (i%2==1) ++a[3];
            else ++a[4];
        }
    }
    for (int i=1;i<=4;++i)
        b[i]=a[i];
    int z=(n+1)/2;
    int zz=n-z;
    int ans1=0;
    if (a[1]<z) {
        x=min(a[3],a[2]);
        ans1+=x;
        a[2]-=x;
        a[3]-=x;
        a[1]+=x;
        a[4]+=x;
    }
    ans1+=a[3]+a[2];
    int ans2=0;
    if (b[3]<z) {
        x=min(b[1],b[4]);
        ans2+=x;
        b[4]-=x;
        b[1]-=x;
        b[3]+=x;
        b[2]+=x;
    }
    ans2+=b[1]+b[4];
    cout<<min(ans1,ans2);
}