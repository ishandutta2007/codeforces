#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
    bool operator < (const Node &other) const {
        if (x == other.x){
            return y < other.y;
        }
        return x < other.x;
    }
};
vector<vector<int> > ans(12, vector<int>(12, 0));
int n, m;
vector<Node> rond(12), god(12);
bool check1() {
    bool f=true;
    int res=0;
    for(int i=0;i<n;i++) {
        if(!f) break;
        for(int j=0;j<m;j++) {
            if((res!=0)&&(ans[i][j]!=0)&&(ans[i][j]!=res)) {
                f = false;
                break;
            }
            if(!res)
                res = ans[i][j];
        }
    }
    if (f) {
        cout << res << endl;
        return 1;
    }
    return 0;
}

bool check2() {
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        int res=0;
        for(int j=0;j<m;j++)
        {
            if(ans[i][j]!=0&&ans[i][j]!=res)
            {
                cnt++;
                res=ans[i][j];
            }
        }
        if (cnt >= 2)return false;
    }
    return true;
}

bool check3() {
    for(int i=0;i<m;i++) {
        int cnt=0;
        int res=0;
        for(int j=0;j<n;j++) {
            if(ans[j][i] && ans[j][i] != res) {
                cnt++;
                res=ans[j][i];
            }
        }
        if(cnt >= 2) {
            return false;
        }
    }
    return true;
}
void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> rond[i].x >> rond[i].y;
    }
    for(int i=0;i<m;i++) {
        cin >> god[i].x >> god[i].y;
    }
}
void solve(){
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            auto p = rond[i], q = god[j];
            int now = 0;
            if (p.x < p.y)swap(p.x, p.y);
            if (q.x < q.y)swap(q.x, q.y);
            if (p.x == q.x && p.y == q.y){
                now = 0;
            }else if (p.y == q.x || p.y == q.y) {
                now = p.y;
            } else if (p.x == q.x || p.x == q.y) {
                now = p.x;
            }
            ans[i][j] = now;
        }
    }

    if(check1())return;
  //  cout<<"Here"<<endl;
    if(check2() && check3())
        cout<<0<<endl;
    else
        cout<<-1<<endl;
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    input();
    solve();
    return 0;
}