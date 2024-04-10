#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e6 + 100;
vector<int> ID;
pair<int,int> a[maxn];
pair<int,int> b[maxn];
int n;
struct BIT{
    int sum[maxn];
    void clear(){
        memset(sum,0,sizeof sum);
    }
    int lowbit(int x){
        return x & (-x);
    }
    void add(int x,int val){
        while (x < maxn){
            sum[x] += val;
            x += lowbit(x);
        }
    }
    int query(int x){
        if (x <= 0)return 0;
        int res = 0;
        while (x){
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
    int query(int l,int r){
        return query(r) - query(l -1);
    }
}bit1,bit2;
int cnt[maxn];
int cnt2[maxn];
inline int get_id(int val){
    return lower_bound(ID.begin(),ID.end(),val) - ID.begin() + 1;
}
int aid[maxn];
pair<int,int> read(){
    int x,y;
    cin>>x>>y;
    ID.push_back(x);
    ID.push_back(x-1);
    ID.push_back(x+1);
    ID.push_back(y);
    ID.push_back(y-1);
    ID.push_back(y+1);
    return make_pair(x,y);
}
void gao(){
    memset(cnt,0,sizeof cnt);
    memset(cnt2,0,sizeof cnt2);
    bit1.clear();
    bit2.clear();
    sort(aid+1,aid + 1 + n,[](int  x,int y){
        return a[x].first < a[y].first;
    });
    vector<pair<int,int> > Q;
    for (int i=1;i<=n;i++){
        Q.push_back(make_pair(a[i].second + 1,i));
    }

    sort(Q.begin(),Q.end(),[](pair<int,int> x,pair<int,int> y){
        return x.first < y.first;
    });
    int ai = n;
    for (int i = ID.size() -1;i >=0;i--){
        int pos = ID[i];
        while (ai >= 1 and a[aid[ai]].first == pos){
            bit1.add(get_id(b[aid[ai]].first),1);
            bit2.add(get_id(b[aid[ai]].second),1);
            ai--;
        }
        while (!Q.empty() and Q.back().first == pos){
            cnt[Q.back().second] += bit1.query(get_id(b[Q.back().second].second+1),ID.size() + 2);
            cnt[Q.back().second] += bit2.query(get_id(b[Q.back().second].first-1));
            cnt2[Q.back().second] += n - ai;
            Q.pop_back();
        }
    }
    bit1.clear();
    bit2.clear();

    sort(aid+1,aid + 1 + n,[](int  x,int y){
        return a[x].second <  a[y].second;
    });
    Q.clear();
    for (int i=1;i<=n;i++){
        Q.push_back(make_pair(a[i].first - 1,i));
    }

    sort(Q.begin(),Q.end(),[](pair<int,int> x,pair<int,int> y){
        return x.first > y.first;
    });
    ai = 1;
    for (int i = 0;i <ID.size();i++){
        int pos = ID[i];
        while (ai <= n and a[aid[ai]].second == pos){
            bit2.add(get_id(b[aid[ai]].second),1);
            bit1.add(get_id(b[aid[ai]].first),1);
            ai++;
        }
        while (!Q.empty() and Q.back().first == pos){
            cnt[Q.back().second] += bit2.query(get_id(b[Q.back().second].first-1));
            cnt[Q.back().second] += bit1.query(get_id(b[Q.back().second].second +1),ID.size() + 2);
            cnt2[Q.back().second] += ai-1;
            Q.pop_back();
        }
    }
    for (int i=1;i<=n;i++){
     //   cerr<<cnt[i]<<" "<<cnt2[i]<<endl;
        if (cnt[i] == cnt2[i])continue;
        else {
            cout<<"NO"<<endl;
            exit(0);
        }
    }
}
signed main(){
    ID.push_back(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        a[i] = read();
        b[i] = read();
        aid[i] = i;
    }
    sort(ID.begin(),ID.end());
    ID.erase(unique(ID.begin(),ID.end()),ID.end());
    gao();
    for (int i=1;i<=n;i++){
        swap(a[i],b[i]);
    }
    gao();
    cout<<"YES"<<endl;
    return 0;
}