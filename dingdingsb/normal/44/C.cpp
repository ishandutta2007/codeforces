#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int n, m;
int fr, to;

int c[maxn];

inline int read(void){
    int s=0,w=1;
    char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-')w=-1;
    for(;ch<='9'&&ch>='0';ch=getchar()) s=s*10+ch-'0';
    return s*w;
}

int main(){
    n=read();m=read();
    for(int i=1;i<=m;i++) 
    {
        fr=read();to=read();
        c[fr]++;
        c[to+1]--;
    }
    for(register int i = 1; i <= n; i++) 
    {
        c[i] = c[i - 1] + c[i];
        if(c[i] == 0){
            cout << i << ' ' << 0 << '\n';
            return 0;
        }
        if(c[i]>1) 
        {
            cout << i << ' ' << c[i] << '\n';
            return 0;
        }
    }
    cout << "OK" << '\n';
    return 0;
}