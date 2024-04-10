#include<bits/stdc++.h>
using namespace std;
int val[1000000*2];
int a[500005];
int k,n,d;

bool getBoolean(int num, int l, int r, int l0, int r0);

inline int read(){
    char ch = getchar();
    int ret =0;
    while (ch<'0'||ch>'9')ch = getchar();
    while (ch>='0'&&ch<='9')ret = ret*10+ch-'0',ch = getchar();
    return ret;
}
void work(int num, int l, int r, int x) {
    if (l==r-1) {
        val[num]=1;
        return;
    }
    int mid=l+r >>1;
    if (x<mid) {
        work(num*2+1,l,mid,x);
    } else {
        work(num*2+2,mid,r,x);
    }
    val[num]=val[num*2+1]|val[num*2+2];
}
bool check(int num, int l, int r, int l0, int r0) {
    if (l0>=r0){
        return false;
    } else if (l0<=l&&r<=r0) {
        return val[num];
    }else{
        return getBoolean(num, l, r, l0, r0);
    }
}
bool getBoolean(int num, int l, int r, int l0, int r0) {
    int mid= l+r >>1;
    bool ans=false;
    if (l0<mid) ans=ans|check(num*2+1,l,mid,l0,r0);
    if (mid<r0) ans=ans|check(num*2+2,mid,r,l0,r0);
    return ans;
}
void input(){
    n = read();k=read();d=read();
    for (int i=0;i<n;i++) {
        a[i]=read();
    }
    sort(a,a+n);
}
void solve(){
    work(0,0,n+1,0);
    for (int i=0;i<n;i++) {
        if (check(0,0,n+1,lower_bound(a,a+n,a[i]-d)-a,i-k+2)) {
            if (i==n-1) {
                printf("YES\n");
                return;
            }
            work(0,0,n+1,i+1);
        }
    }
    printf("NO\n");
}
int main() {
    input();
    solve();
    return 0;
}