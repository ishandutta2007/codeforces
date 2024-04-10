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

string s, t;
int n, m;
int sa_cont[110000];
int sb_count[110000];
int ta_cont[110000];
int tb_count[110000];

int q;

void prepare(){
    n = s.size();
    m = t.size();
    for(int i = 1;i <= n;i++){
        if(s[i-1] == 'A'){
            sa_cont[i] = sa_cont[i-1] + 1;
            sb_count[i] = sb_count[i-1];
        }
        else{
            sa_cont[i] = 0;
            sb_count[i] = sb_count[i-1] + 1;
        }
        
    }
    for(int i = 1;i <= m;i++){
        if(t[i-1] == 'A'){
            ta_cont[i] = ta_cont[i-1] + 1;
            tb_count[i] = tb_count[i-1];
        }
        else{
            ta_cont[i] = 0;
            tb_count[i] = tb_count[i-1] + 1;
        }
        
    }
}

int solve(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int last_a = min(ta_cont[d],  d-c+1);
    if(sa_cont[b] < last_a || b - a + 1 < last_a)return false;
    b -= last_a;
    d -= last_a;
    int s_cnt = b>=a?sb_count[b] - sb_count[a-1]:0;
    int t_cnt = d>=c?tb_count[d] - tb_count[c-1]:0;
    if(d<c){
        return s_cnt == 0 && (b-a+1) % 3 == 0;
    }
    if(b<a)return false;
    if(s[b-1] == 'A'){
        int a_cnt = min(b-a+1, sa_cont[b]);
        if(a_cnt % 3)s_cnt += 2;
    }
    if(s_cnt % 2 != t_cnt % 2)return false;
    return s_cnt <= t_cnt;
}

int main(){
    cin >> s >> t;
    cin >> q;
    prepare();
    while(q--)printf("%d", solve());
    puts("");
    return 0;
}