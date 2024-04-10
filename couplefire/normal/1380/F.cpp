#include<bits/stdc++.h>
using namespace std;
int m, n;
const int mxn = (5e5) + 5;
int mod = 998244353;
int c[mxn];
struct node{
    int ans;
    int ans_L;
    int ans_R;
    int ans_LR;
} st[mxn * 4];
 
int sm[100];
int sum(int x, int y){
    return (x + y) % mod;
}
int mul(int x, int y){
    return (1LL * x * y) % mod;
}
void merge(int p, int l, int r){
    int md = (l + r) / 2;
 
    int d2 = (sm[c[md] * 10 + c[md + 1]]) * (c[md] != 0);
 
    int vl1 = mul(st[p * 2].ans, st[p * 2 + 1].ans);
    int vl2 = mul(mul(st[p * 2].ans_R, st[p * 2 + 1].ans_L), d2) ;
    st[p].ans = sum(vl1, vl2);
    
    vl1 = mul(st[p * 2].ans_L, st[p * 2 + 1].ans);
    vl2 = mul(mul(st[p * 2].ans_LR, st[p * 2 + 1].ans_L), d2);
    st[p].ans_L = sum(vl1, vl2);
 
    vl1 = mul(st[p * 2].ans, st[p * 2 + 1].ans_R);
    vl2 = mul(mul(st[p * 2].ans_R, st[p * 2 + 1].ans_LR), d2);
    st[p].ans_R = sum(vl1, vl2);
 
    vl1 = mul(st[p * 2].ans_L, st[p * 2 + 1].ans_R);    
    vl2 = mul(mul(st[p * 2].ans_LR, st[p * 2 + 1].ans_LR), d2);
    st[p].ans_LR = sum(vl1, vl2);
}
void build(int p, int l, int r){
    if(l == r){
        st[p].ans = sm[c[l]];
        st[p].ans_L = 1;
        st[p].ans_R = 1;
        st[p].ans_LR = 0;
        return;
    }
    int md = (l + r) / 2;
    build(p * 2, l, md);
    build(p * 2 + 1, md + 1, r);
    merge(p, l, r);
}
void update(int p, int l,int r, int i){
    if(l == r){
        st[p].ans = sm[c[l]];
        st[p].ans_L = 1;
        st[p].ans_R = 1;
        st[p].ans_LR = 0;
        return;
    }
    int md = (l + r) / 2;
    if(i <= md)update(p * 2, l, md, i);
    else update(p * 2 + 1, md + 1, r, i);
    merge(p, l, r);
}
int main()
{
    for(int i = 0 ; i <= 18 ; ++i){
        for(int d1 = 0 ; d1 <= 9 ; ++d1)
            for(int d2 = 0 ; d2 <= 9 ; ++d2)
                sm[i] += ((d1 + d2) == i);
    }
    
    scanf("%d%d", &n, &m);
    string s;
    cin>>s;
    for(int i = 1; i <= n ; ++i)c[i] = s[i - 1] - '0'; 
    build(1, 1, n);
    while(m--){
        int x, d;
        scanf("%d%d", &x, &d);
        c[x] = d;
        update(1, 1, n, x);
        printf("%d\n", st[1].ans);
    }
    return 0;
}