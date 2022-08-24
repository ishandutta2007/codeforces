#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
struct Vertex{int rock; int paper; int scissor;};
vector<Vertex> rmq;
void renew(int i){
    rmq[i].paper = rmq[2*i+1].paper + rmq[2*i+2].paper;
    rmq[i].scissor = rmq[2*i+1].scissor + rmq[2*i+2].scissor;
    rmq[i].rock = rmq[2*i+1].rock + rmq[2*i+2].rock;
}
void create(int i, int l, int r, string &s){
    if (r-l==1){
        if (s[l] == 'R') rmq[i].rock++;
        if (s[l] == 'P') rmq[i].paper++;
        if (s[l] == 'S') rmq[i].scissor++;
        return;
    }
    int mid = (l+r)/2;
    create(2*i+1, l, mid, s), create(2*i+2, mid, r, s);
    renew(i);
}
void change(int i, int l, int r, int ind, char ch){
    if (r-l==1){
        rmq[i] = {0, 0, 0};
        if (ch == 'R') rmq[i].rock++;
        if (ch == 'P') rmq[i].paper++;
        if (ch == 'S') rmq[i].scissor++;
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) change(2*i+1, l, mid, ind, ch);
    else change(2*i+2, mid, r, ind, ch);
    renew(i);
}
int n;
int gl(int i, int l, int r, char ch){
    if (ch== 'S'){
        if (rmq[i].scissor == 0) return -1;
        if (r-l==1) return l;
        int mid = (l+r)/2;
        if (rmq[2*i+1].scissor > 0) return gl(2*i+1, l, mid, ch);
        else return gl(2*i+2, mid, r, ch);
    }
    else if (ch == 'P'){
        if (rmq[i].paper == 0) return -1;
        if (r-l==1) return l;
        int mid = (l+r)/2;
        if (rmq[2*i+1].paper > 0) return gl(2*i+1, l, mid, ch);
        else return gl(2*i+2, mid, r, ch);
    }
    if (rmq[i].rock == 0) return -1;
    if (r-l==1) return l;
    int mid = (l+r)/2;
    if (rmq[2*i+1].rock > 0) return gl(2*i+1, l, mid, ch);
    else return gl(2*i+2, mid, r, ch);
}
int gr(int i, int l, int r, char ch){
    if (ch == 'S'){
        if (rmq[i].scissor == 0) return -1;
        if (r-l==1) return l;
        int mid = (l+r)/2;
        if (rmq[2*i+2].scissor > 0) return gr(2*i+2, mid, r, ch);
        else return gr(2*i+1, l, mid, ch);
    }
    else if (ch == 'P'){
        if (rmq[i].paper == 0) return -1;
        if (r-l==1) return l;
        int mid = (l+r)/2;
        if (rmq[2*i+2].paper > 0) return gr(2*i+2, mid, r, ch);
        else return gr(2*i+1, l, mid, ch);
    }
    if (rmq[i].rock == 0) return -1;
    if (r-l==1) return l;
    int mid = (l+r)/2;
    if (rmq[2*i+2].rock > 0) return gr(2*i+2, mid, r, ch);
    else return gr(2*i+1, l, mid, ch);
}
int rget(int i, int l, int r, int l1, int r1, char ch){
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1){
        if (ch == 'P') return rmq[i].paper;
        if (ch == 'S') return rmq[i].scissor;
        if (ch == 'R') return rmq[i].rock;
    }
    int mid = (l+r)/2;
    return rget(2*i+1, l, mid, l1, min(r1, mid), ch) + rget(2*i+2, mid, r, max(l1, mid), r1, ch);
}
int get(int l, int r, char ch){
    if (l >= r) return 0;
    return rget(0, 0, n, l, r, ch);
}
void calc(){
    pair<int, int> S, P, R;
    S = {gl(0, 0, n, 'S'), gr(0, 0, n, 'S')};
    P = {gl(0, 0, n, 'P'), gr(0, 0, n, 'P')};
    R = {gl(0, 0, n, 'R'), gr(0, 0, n, 'R')};
    int ans = 0;
    if (rmq[0].scissor == 0) ans += rmq[0].paper;
    else if (rmq[0].scissor > 0 && rmq[0].rock > 0){
        ans += rmq[0].paper;
        ans -= get(R.second, S.second, 'P');
        ans -= get(S.first, R.first, 'P');
    }
    if (rmq[0].paper == 0) ans += rmq[0].rock;
    else if (rmq[0].scissor > 0 && rmq[0].paper > 0){
        ans += rmq[0].rock;
        ans -= get(S.second, P.second, 'R');
        ans -= get(P.first, S.first, 'R');
    }
    if (rmq[0].rock == 0) ans += rmq[0].scissor;
    else if (rmq[0].rock > 0 && rmq[0].paper > 0){
        ans += rmq[0].scissor;
        ans -= get(P.second, R.second, 'S');
        ans -= get(R.first, P.first, 'S');
    }
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i=0; i < 4*n; i++) rmq.push_back({0, 0, 0});
    create(0, 0, n, s);
    calc();
    for (int i=0; i < q; i++){
        int index;
        char ch;
        cin >> index >> ch;
        change(0, 0, n, index-1, ch);
        calc();
    }
    return 0;
}