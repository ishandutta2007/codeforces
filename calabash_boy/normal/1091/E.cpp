// Created by calabash_boy on 18-10-18.
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LImaxnE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
const int maxn = 5e5+1000;
int n,a[maxn],b[maxn];
int s;
int check(int x) {
    a[n]=x;
    if (x>=n) return 1;

    rep(i,1,n) {
        a[i]=b[i];
    }
    sort(a+1,a+1+n,[](int x,int y){
        return x > y;
    });
    for (ll i=1,j=n,sum = 0,S = 0;i<=n;i++) {
        sum+=a[i];
        while (j>i&&a[j]<=i) {
            S+=a[j];
            j--;
        }
        if (j<i) {
            S-=a[i];
        }
        ll temp = i*(i-1)+S+(max(0ll,j-i))*i;
        if (sum> temp) {
            if (a[i]>x) return 0;
            return 1;
        }
    }
    return 2;
}
int L_ANS,R_ANS;
void input(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if (b[i] & 1){
            s++;
        }
    }
    s&=1;
    n++;
}
void solve1(){
    int l=0;
    int r=(n-1)/2;
    L_ANS=-1;
    while (l<=r) {
        int mid=l + r >> 1;
        int tar = 2 * mid +s;
        int res=check(tar);
        if (res==2) {
            r=mid-1;
            L_ANS=mid;
        }else if (res==0){
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
}
void solve2(){
    int l=L_ANS,r=(n-1)/2;
    R_ANS=-1;
    while (l<=r) {
        int mid=l + r >> 1;
        int tar = 2 * mid +s;
        int res=check(tar);
        if (res==2) {
            l=mid+1;
            R_ANS=mid;
        }else {
            r=mid-1;
        }
    }
}
void output(){
    REP(i,L_ANS,R_ANS){
        printf("%d ",2 * i +s);
    }
    puts("");
}
int main() {
    input();

    solve1();
    cerr<<L_ANS<<endl;
    if (L_ANS==-1) {
        puts("-1");
        exit(0);
    }

    solve2();
    cerr<<R_ANS<<endl;
    output();

    return 0;
}