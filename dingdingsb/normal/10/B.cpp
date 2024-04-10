#include <bits/stdc++.h>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=(X<<3)+(X<<1)+c-'0',c=getchar();
    return X*w;
}

bool a[110][110];

int main() {
    int n=read(),k=read();
    int xc=(k+1)/2,yc=(k+1)/2;
    while (n--) {
        int x=read();
        int X,Y,Min=2147483647;
        for (re int i=1;i<=k;i++)
            for (re int j=1;j<=k-x+1;j++) {
                bool f=1; int s=0;
                for (re int t=j;t<j+x;t++) {
                    if (a[i][t]) { f=0; break; }
                    s+=abs(i-xc)+abs(t-yc);
                }
                if (f&&s<Min) Min=s,X=i,Y=j;
            }
        if (Min==2147483647) puts("-1");
        else {
            for (re int i=Y;i<Y+x;i++) a[X][i]=1;
            printf("%d %d %d\n",X,Y,Y+x-1);
        }
    }           
    return 0;
}