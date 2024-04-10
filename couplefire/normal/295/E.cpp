#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAX 2000000100
#define MIN -2000000100
long long pos[MAXN];
long long n;

struct Node{
    Node *L, *R;
    long long sum, cnt, ans;
    Node(){L=R=NULL;sum=cnt=ans=0;}
} root, zero;

void make(Node &id){
    if(id.L ==  NULL) id.L = new Node();
    if(id.R == NULL) id.R = new Node();
    return;
}

Node merge(Node c, Node a, Node b){
    c.sum = a.sum + b.sum;
    c.cnt = a.cnt + b.cnt;
    c.ans = a.ans + b.ans + a.cnt*b.sum-b.cnt*a.sum;
    return c;
}

void add(long long p, long long val, long long l=MIN, long long r=MAX, Node &id=root){
    if(p < l || p >= r) return;
    if(r-l == 1){
        id.ans = 0;
        id.cnt += val;
        id.sum += p*val;
        return;
    }
    make(id);
    long long mid = (l+r)/2;
    add(p, val, l, mid, *id.L);
    add(p, val, mid, r, *id.R);
    id=merge(id, *id.L, *id.R);
}

Node get(long long x, long long y, long long l=MIN, long long r=MAX, Node &id=root){
    if(y <= l || x >= r) return zero;
    if(x <= l && y >= r) return id;
    long long mid = (l+r)/2;
    Node rl, rr;
    if(id.L != NULL) rl = get(x, y, l, mid, *id.L);
    if(id.R != NULL) rr = get(x, y, mid, r, *id.R);
    return merge(id, rl, rr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(long long i = 0; i<n; i++){
        long long p; cin >> p;
        pos[i]=p;
        add(pos[i], 1);
    }
    long long q; cin >> q;
    while(q--){
        long long type; cin >> type;
        if(type == 2){
            long long x, y; cin >> x >> y;
            cout << get(x, y+1).ans << endl;
        }
        else{
            long long i, p; cin >> i >> p;
            i--;
            add(pos[i], -1);
            pos[i] += p;
            add(pos[i], 1);
        }
    }
}