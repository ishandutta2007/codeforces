#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300000
#define FK 5000
#define INF 0x3f3f3f3f

int TR(char now){
    if(now >= 'a' && now <= 'z') return now - 'a';
    if(now >= 'A' && now <= 'Z') return now - 'A' + 26;
    if(now >= '0' && now <= '9') return now - '0' + 52;
}
char STR(int now){
    if(now >= 0 && now < 26) return now + 'a';
    if(now >= 26 && now < 52) return now - 26 + 'A';
    return now - 52 + '0';
}
int n , use[MAX] , aat[MAX];
string s[MAX];
vector<int> v[MAX] , in[MAX];
vector<int> ans;
set<PII> cc;
void solve(int now){
    int cnt = 0;
    while(aat[now] < v[now].size()){
        int to = v[now][aat[now] ++];
        solve(to);
    }
    ans.pb(now);
}
int32_t main(){
    IOS;
    cin >> n;
    int good;
    REP(i , 0 , n){
        cin >> s[i];
        int a = TR(s[i][0]) , b = TR(s[i][1]) , c = TR(s[i][2]);
        int vala = a * 65 + b;  
        int valb = b * 65 + c;
        good = vala;
        v[vala].pb(valb);
        in[valb].pb(vala);
    }
    int fr = -1 , ba = -1;
    REP(i , 0 , FK){
        int outnow = v[i].size();
        int intnow = in[i].size();
        if(outnow == intnow) continue;
        else if(outnow - intnow == 1){
            if(fr != -1){
                cout << "NO" << endl;
                return 0;
            }
            else fr = i;
        }
        else if(intnow - outnow == 1){
            if(ba != -1){
                cout << "NO" << endl;
                return 0;
            }
            else ba = i;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(fr == -1) fr = ba = good;

    solve(fr);
    string aans;
    RREP(i , ans.size() - 1 , 0){
        int a = ans[i] / 65 , b = ans[i] % 65;
        if(i + 1 == ans.size()){
            aans += STR(a);
            aans += STR(b);
        }
        else aans += STR(b);
    }
    if(aans.size() == n + 2){
        cout << "YES" << endl;
        cout << aans << endl;
    }
    else cout << "NO" << endl;
    return 0;
}