#include <bits/stdc++.h>
#define int long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
bool Good(int symb){
    int code = '0';
    if (symb - code >= 0 && symb - code <= 9) return true;
    return false;
}
pair<bool, pair<int, int> > parse(){
    string s;
    cin >> s;
    int num = 0, base = (1<<24), ans=0;
    s += "/32/";
    for (int i=1; i < s.size(); i++){
        if (Good(s[i])){
            num *= 10;
            num += (s[i] - '0');
        }
        else{
            if (base == 0){
                return {(s[0] == '+'), {ans, ans+(1LL<<(32-num))-1}};
            }
            ans += num*base;
            base/=(1<<8);
            num = 0;
        }
    }
}
struct Event{int tp; int brd;};
bool cmp(Event &a, Event &b){
    if (a.brd != b.brd) return (a.brd < b.brd);
    return (a.tp > b.tp);
}
void In(vector<pair<int, int> > &a, vector<pair<int, int> > &b){
    vector<Event> ev;
    for (int i = 0; i < a.size(); i++){
        ev.push_back({2, a[i].first});
        ev.push_back({3, a[i].second+1});
    }
    for (int i = 0; i < b.size(); i++){
        ev.push_back({0, b[i].first});
    }
    int A=0;
    sort(ev.begin(), ev.end(), cmp);
    for (int i=0; i < ev.size(); i++){
        if (ev[i].tp == 2) A++;
        else if (ev[i].tp == 3) A--;
        else{
            if (A){
                cout << -1;
                exit(0);
            }
        }
    }

}
set<int> W, B;
vector<pair<int, int> > ans;
bool Is(set<int> &a, int L, int R){
    if (a.lower_bound(L) == a.end()) return false;
    if (a.lower_bound(R+1) == a.end()) return true;
    int A = *(a.lower_bound(L));
    int B = *(a.lower_bound(R+1));
    return (A!=B);
}
void solve(int L, int R){
    bool A = Is(W, L, R), b = Is(B, L, R);
    if (!b) return;
    if (!A){
        ans.push_back({L, R});
        return;
    }
    int mid = (L+R)/2;
    solve(L, mid), solve(mid+1, R);
}
void Print(pair<int, int> res){
    int L = res.first, R = res.second+1;
    int df = R-L;
    //cout << L << " " <<R  << endl;
    vector<int> kok;
    int ded = (1<<8);
    for (int i=0;i<4;i++){
        kok.push_back(L%ded);
        L/=ded;
    }
    reverse(kok.begin(), kok.end());
    for (int i=0;i<4;i++){
        cout << kok[i];
        if (i < 3) cout << ".";
        else cout << "/";
    }
    int delt = 32;
    //cout << df << endl;
    while (df!=1){
        df /= 2;
        delt--;
    }
    cout << delt << endl;
}
signed main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    vector<pair<int, int> > black, white;
    cin >> n;
    for (int i=0; i < n; i++){
        pair<bool, pair<int, int> > res = parse();
        //cout << res.first << " " << res.second.first << " " << res.second.second << endl;
        if (res.first) white.push_back(res.second);
        else black.push_back(res.second);
    }
    In(black, white);
    In(white, black);
    for (int i=0; i < white.size(); i++) W.insert(white[i].first);
    for (int i=0; i < black.size(); i++) B.insert(black[i].first);
    solve(0, (1LL<<32)-1);
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) Print(ans[i]);

}