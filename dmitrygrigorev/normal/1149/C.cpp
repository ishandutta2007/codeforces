#include <bits/stdc++.h>
using namespace std;
const int INF=1e8;
struct Vertex {int maximum; int minimum; int ps; int right_max; int left_max;};
vector<Vertex> rmq;
vector<int> arr;
void recalc(Vertex &a, Vertex &b, Vertex &c){
    a.maximum = max(b.maximum, c.maximum);
    a.minimum = min(b.minimum, c.minimum);
    a.right_max = max(b.right_max, max(c.right_max, c.maximum - 2*b.minimum));
    a.left_max = max(b.left_max, max(c.left_max, b.maximum - 2*c.minimum));
}
void build(int i, int l, int r){
    if (r-l==1){
        int T = arr[l];
        rmq[i] = {T,T,0,-T,-T};
        return;
    }
    int mid = (l+r)/2;
    build(2*i+1, l, mid);
    build(2*i+2, mid, r);
    recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);
}
void add_cur(int index, int P){
    rmq[index].maximum += P;
    rmq[index].minimum += P;
    rmq[index].ps += P;
    rmq[index].right_max -= P;
    rmq[index].left_max -= P;
}
void push(int i, int l, int r){
    if (r-l <= 1) return;
    int P = rmq[i].ps;
    if (P==0) return;
    rmq[i].ps = 0;
    add_cur(2*i+1, P);
    add_cur(2*i+2, P);
}
void add(int i, int l, int r, int l1, int r1, int value){
    push(i, l, r);
    if (l1 >= r1) return;
    if (l==l1 && r==r1){
        add_cur(i, value);
        return;
    }
    int mid = (l+r)/2;
    add(2*i+1, l, mid, l1, min(r1, mid), value);
    add(2*i+2, mid, r, max(l1, mid), r1, value);
    recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);
    //cout << i << " " << l << " " << r << " " << rmq[i].maximum << endl;
}
pair<int, int> go(int i, int l, int r){
    if (r-l==1) return {rmq[i].maximum, l};
    push(i, l, r);
    int mid = (l+r)/2;
    if (rmq[2*i+1].maximum == rmq[i].maximum) return go(2*i+1, l, mid);
    return go(2*i+2, mid, r);
}
Vertex answer, tet;
void down(int i, int l, int r, int l1, int r1){
    push(i, l, r);
    if (l1 >= r1) return;
    if (l==l1 && r==r1){
        tet = answer;
        recalc(answer, tet, rmq[i]);
        return;
    }
    int mid = (l+r)/2;
    down(2*i+1, l, mid, l1, min(r1, mid));
    down(2*i+2, mid, r, max(l1, mid), r1);
}
int get_ans(int N){
    pair<int, int> p = go(0, 0, N);
    int val = p.first, ind = p.second;
    answer = {-INF, INF, -1, 0, 0};
    int mx=0;
    down(0, 0, N, ind+1, N);
    mx = max(mx, answer.right_max);
    answer = {-INF, INF, -1, 0, 0};
    down(0, 0, N, 0, ind);
    mx = max(mx, answer.left_max);
    //cout << mx << endl;
    return val+mx;
}
main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    arr.push_back(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i=0; i < 2*n-2; i++){
        if (s[i] == '(') arr.push_back(arr.back() + 1);
        else arr.push_back(arr.back() - 1);
    }
    int N = arr.size();
    rmq.resize(4*N, {});
    build(0, 0, N);
    cout << get_ans(N)  << "\n";
    //for (int i=0;i<N;i++) cout << arr[i] << " ";
    //cout << endl;
    for (int i=0; i < q; i++){
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        bool open = (s[l-1] == '(');
        swap(s[l-1], s[r-1]);
        if (open){
            //cout << l << " " << r-1 << " " << -2 << endl;
            add(0, 0, N, l, r, -2);
        }
        else{
            //cout << l << " " << r-1 << " " << -2 << endl;
            add(0, 0, N, l, r, 2);
        }
        cout << get_ans(N) << "\n";
    }
    return 0;
}