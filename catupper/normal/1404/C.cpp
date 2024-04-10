#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

int last_dif[330000];
int dif[330000];
int need[330000];

int underr[330000], overl[330000];

void add(int l, int r){
    underr[r]++;
    overl[l]++;
}

int n;

int solve(int l, int r){
    return underr[r] + overl[l] - n;
}

vector<vector<int>> lists;

int cnt = 0;
int len = 0;
void clean(){
    vector<int> tmp;
    for(auto &v:lists){
        for(auto &elem:v){
            tmp.push_back(elem);
        }
    }    
    lists.clear();
    for(int i = 0;i < tmp.size();i++){
        if(i % 600 == 0)lists.push_back({});
        lists.back().push_back(tmp[i]);
    }
}

void insert(int x){
    cnt++;
    len++;
    if(cnt % 600 == 0)clean();
    if(lists.empty()){
        lists.push_back({x});
        return;
    }
    for(int i = 0;i < lists.size();i++){
        if(i + 1 != lists.size() && lists[i].back() >= x)continue;
        lists[i].push_back(x);
        for(int j = lists[i].size() - 1;j > 0;j--){
            if(lists[i][j] <= lists[i][j-1])break;
            swap(lists[i][j], lists[i][j-1]);
        }
        return;
    }
}

int get(int ind){
    int i = 0;
    while(lists[i].size() <= ind){
        ind -= lists[i].size();
        i++;        
    }
    return lists[i][ind];
}
    
vector<P> queries[330000];
vector<int> x[330000];
int bit[330000];
int ans[330000];
void add_bit(int x){
    x++;
    while(x < 330000){
        bit[x]++;
        x += x & -x;
    }
}

int cnt_bit(int x){
    x++;
    int ans = 0;
    while(x){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    int  q, a;
    scanf("%d%d", &n, &q);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a);
        dif[i] = i - a;
        if(dif[i] < 0)dif[i] = 320000;
        if(dif[i] == 0){          
            insert(i);
            need[i] = i;
        }else{
            if(len > dif[i] - 1){
                need[i] = get(dif[i]-1);
                insert(need[i]);
            }
        }
        x[need[i]].push_back(i);
    }
    for(int i = 1;i < 330000;i++){
        underr[i] += underr[i-1];
    }
    for(int i = 330000-2;i >= 0;i--){
        overl[i] += overl[i+1];
    }
    for(int i = 0;i < q;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        int l = x + 1, r = n - y;
        queries[l].push_back(P(r, i));
    }
    for(int i = 330000-1;i >= 0;i--){
        for(auto y: x[i]){
            add_bit(y);
        }
        for(auto q:queries[i]){
            int r = q.first, ind = q.second;
            ans[ind] = cnt_bit(r);            
        }
    }
    for(int i = 0;i < q;i++)printf("%d\n", ans[i]);
    return 0;
}