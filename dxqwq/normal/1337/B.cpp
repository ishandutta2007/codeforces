#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    char ch=getchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x;
}
int n,x,m;
signed main() {
    int T=read();
    while(T--) {
        x=read();
        n=read();
        m=read();
        while(n&&x>20) {
            x=x/2+10;
            n--;
        }
        if(m*10>=x) puts("Yes"); else puts("No");
    }
    return 0;
}