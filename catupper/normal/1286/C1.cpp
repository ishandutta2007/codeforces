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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

map<vector<int>, int> cntcnt;

void ask(int l, int r, int val){
    cout << "? " << l << " " << r << endl;
    int len = r - l + 1;
    string str;
    for(int i = 0;i < (len + 1) * len / 2;i++){
        cin >> str;
        vector<int> cnt(26, 0);
        for(char c: str)cnt[c-'a']++;
        cntcnt[cnt] += val;
    }
}

int main(){
    int n;
    cin >> n;
    if(n <= 3){
        string ans = "";
        for(int i = 1;i <= n;i++){
            char c;
            cout << "? " << i << " " << i<< endl;
            cin >> c;
            ans += c;
        }
        cout << "! " << ans << endl;
        return 0;
    }
    ask(1, n, 1);
    ask(2, n, -1);
    vector<vector<int> > clue(n+1);
    for(auto tmp:cntcnt){
        if(tmp.second == 0)continue;
        int sum = 0;
        for(auto elem:tmp.first)sum += elem;
        clue[sum] = tmp.first;
    }
    clue[0] = vector<int>(26,0);
    string ans;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 26;j++){
            if(clue[i-1][j] != clue[i][j]){
                ans += char('a' + j);
            }
        }
    }
    cout <<"! " <<  ans << endl;
    return 0;
}