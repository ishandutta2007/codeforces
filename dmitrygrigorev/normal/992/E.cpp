#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> rmq_sum;
vector<int> v, rmq_max;
int n;
void create(int i, int l, int r){
    if (r-l==1){
        rmq_sum[i] = v[l], rmq_max[i] = v[l];
        return;
    }
    int mid = (l+r)/2;
    create(2*i+1, l, mid);
    create(2*i+2, mid, r);
    rmq_sum[i] = rmq_sum[2*i+1] + rmq_sum[2*i+2];
    rmq_max[i] = max(rmq_max[2*i+1], rmq_max[2*i+2]);
}
void change(int i, int l, int r, int ind, int num){
    if (r-l==1){
        rmq_sum[i] = num, rmq_max[i] = num;
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) change(2*i+1, l, mid, ind, num);
    else change(2*i+2, mid, r, ind, num);
    rmq_sum[i] = rmq_sum[2*i+1] + rmq_sum[2*i+2];
    rmq_max[i] = max(rmq_max[2*i+1], rmq_max[2*i+2]);
}
int down(int i, int l, int r, LL S){
    if (r-l==1) return l;
    int mid = (l+r)/2;
    if ((LL) rmq_max[2*i+1] >= S) return down(2*i+1, l, mid, S);
    return down(2*i+2, mid, r, S);
}
int get(int i, int l, int r, int l1, int r1, LL S){
    if (l1 >= r1) return n;
    if (l==l1 && r==r1){
        if ((LL) rmq_max[i] < S) return n;
        return down(i, l, r, S);
    }
    int mid = (l+r)/2;
    int res = get(2*i+1, l, mid, l1, min(r1, mid), S);
    if (res != n) return res;
    return get(2*i+2, mid, r, max(l1, mid), r1, S);
}
LL get_sum(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1) return rmq_sum[i];
    int mid = (l+r)/2;
    return get_sum(2*i+1, l, mid, l1, min(r1, mid)) + get_sum(2*i+2, mid, r, max(l1, mid), r1);
}
pair<LL, bool> check(int ind){
    LL a = get_sum(0, 0, n, 0, ind);
    LL b = get_sum(0, 0, n, ind, ind+1);
    return {a+b, (a==b)};
}
int ask(){
    int ind = 0;
    LL sum = 0;
    while (ind < n){
        int new_ind = get(0, 0, n, ind, n, sum);
        if (new_ind == n) break;
        pair<LL, bool> p = check(new_ind);
        if (p.second) return new_ind+1;
        ind = new_ind+1;
        sum = p.first;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> n >> q;
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i=0; i < 4*n; i++){
        rmq_sum.push_back(0);
        rmq_max.push_back(0);
    }
    create(0, 0, n);
    for (int i=0; i < q; i++){
        int ind, num;
        cin >> ind >> num;
        change(0, 0, n, ind-1, num);
        cout << ask() << endl;
    }
}