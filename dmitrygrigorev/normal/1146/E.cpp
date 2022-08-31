#include <bits/stdc++.h>
#define int long long
using namespace std;
//vector<vector<pair<int, int> > > rmq;
vector<pair<int, int> > v;
vector<int> ans;
const int K = 200000;
pair<int, int> pos[K];
struct Update{int l; int r; int tp; int tm;};
struct Event{int what; int tp; int pos; int cl;};
bool cmp(Event &a, Event &b){
    if (a.what != b.what)return (a.what < b.what);
    return (a.cl < b.cl);
}
vector<int> rmq;
void updt(int i, int l, int r, int ind, int ct){
    if (r-l==1){
        rmq[i] += ct;
        return;
    }
    int mid = (l+r)/2;
    if (ind < mid) updt(2*i+1, l, mid, ind, ct);
    else updt(2*i+2, mid, r, ind, ct);
    rmq[i] = rmq[2*i+1] + rmq[2*i+2];
}
int get(int i, int l, int r, int l1, int r1){
    if (l1 >= r1) return 0;
    if (l==l1 && r==r1) return rmq[i];
    int mid = (l+r)/2;
    return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);
}
main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector<int> val;
    for (int i=0; i < n; i++){
        int u;
        cin >> u;
        int e = u;
        if (e < 0) e *= -1;
        val.push_back(e);
        if (u < 0){
             v.push_back({-u, i});
             ans.push_back(0);
        }
        else{
            v.push_back({u, i});
            ans.push_back(1);
        }
    }
    rmq.resize(4*n, {});
    sort(v.begin(), v.end());
    int start = 0;
    for (int i=0; i < K; i++){
        int finish = start;
        while (finish < n && v[finish].first == i) finish++;
        pos[i] = {start, finish-1};
        start = finish;
    }
    vector<Update> upd;
    for (int i=0; i < q; i++){
        char ch;
        int x;
        cin >> ch >> x;
        int T = x;
        if (x < 0) T = -x;
        int R = pos[T].second, L = pos[T].first;
        //cout << ":::" << L << " " << R << endl;
        if (ch == '>'){
            upd.push_back({R+1, n, -1, i});
            if (x < 0){
                upd.push_back({0, L, 0, i});
                upd.push_back({L, R+1, -1, i});
            }
        }
        else{
            upd.push_back({R+1, n, 1, i});
            if (x > 0){
                upd.push_back({0, L, 0, i});
                upd.push_back({L, R+1, 1, i});
            }
        }
    }
    vector<Event> ev;
    for (int i=0; i < upd.size(); i++){
        ev.push_back({upd[i].l, upd[i].tp, upd[i].tm, 0});
        ev.push_back({upd[i].r, upd[i].tp, upd[i].tm, 1});
    }
    sort(ev.begin(), ev.end(), cmp);
//    for (int i=0; i < ev.size(); i++){
//        cout << ev[i].what << " " << ev[i].pos << " " << ev[i].tp << " " << ev[i].cl << endl;
//    }
    rmq.resize(4*q, 0);
    multiset<pair<int, int> > heavy;
    int u = 0;
    for (int i=0; i < n; i++){
        //cout << i << endl;
        while (u < ev.size() && ev[u].what == i){
          //  cout << u << "!!" << ev.size() << " " << ev[u].pos << " " << ev[u].tp << " " << ev[u].cl << endl;
            if (ev[u].tp == -1 || ev[u].tp == 1){
                if (ev[u].cl == 0) heavy.insert({ev[u].pos, ev[u].tp});
                else heavy.erase(heavy.find({ev[u].pos, ev[u].tp}));
            }
            else{
                if (ev[u].cl == 0) updt(0, 0, q, ev[u].pos, 1);
                else updt(0, 0, q, ev[u].pos, -1);
            }
            u++;
        }
        //cout << i << "??" << heavy.size() << endl;
        if (heavy.size() == 0){
            int S = rmq[0]%2;
            ans[v[i].second]^=S;
            //cout << ":::" << i << " " << S << " " << v[i].second << endl;
        }
        else{
            auto it = heavy.end();
            it--;
            pair<int, int> p = (*it);
            int kek;
            if (p.second == -1) kek = 0;
            else kek=1;
          //  cout << i << " " << p.first << " " << p.second << endl;
            ans[v[i].second] = (get(0, 0, q, p.first+1, q)%2) ^ (kek%2);
        }
    }
    for (int i=0;i<n;i++){
        int T = ans[i];
        if (T==0) cout << -val[i];
        else cout << val[i];
        cout << " ";
    }
}