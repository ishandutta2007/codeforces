#include <bits/stdc++.h>
using namespace std;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

string s[MAX];
int n , k;
int trie[MAX][30] , po = 2;
void Build(int now , int id , int floor){
    if(floor == s[id].size()) return;
    else{
        int val = s[id][floor] - 'a';
        if(trie[now][val] == 0) trie[now][val] = po ++;
        Build(trie[now][val] , id , floor + 1);
    }
}
int solve1(int now){
    int val = 0;
    REP(i , 0 , 30){
        if(trie[now][i] && solve1(trie[now][i]) == 0){
            val = 1;
        }
    }
    return val;
}
int solve2(int now){
    int vis = 0 , val = 0;
    REP(i , 0 , 30){
        if(trie[now][i]){
            vis = 1;
            if(solve2(trie[now][i]) == 0) val = 1;
        }
    }
    if(vis == 0) return 1;
    else return val;
}
int32_t main(){
    IOS;
    cin >> n >> k;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n) Build(1 , i , 0);

    int win = solve1(1) , lose = solve2(1);

    if(win && lose) cout << "First" << endl;
    else if(win){
        if(k % 2 == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    else if(lose) cout << "Second" << endl;
    else cout << "Second" << endl;
    return 0;
}