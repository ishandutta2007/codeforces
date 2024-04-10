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

vector<int> cnts[220000];
vector<int> cnt(26, 0);    
string str;
int q, l, r;

int main(){
    cin >> str;
    int n = str.size();
    for(int i = 0;i < n;i++){
        cnts[i] = cnt;
        cnt[str[i] - 'a']++;
    }
    cnts[n] = cnt;
    cin >> q;
    for(int i = 0;i < q;i++){
        cin >> l >> r;l--,r--;
        cnt = cnts[r+1];
        int kind = 0;
        for(int i = 0;i < 26;i++){
            cnt[i] -= cnts[l][i];
            if(cnt[i])kind++;
        }
        if(kind > 2){
            printf("Yes\n");
            continue;
        }
        if(kind == 2){
            if(str[l] == str[r]) printf("No\n");
            else printf("Yes\n");
            continue;
        }
        if(kind == 1){
            if(r == l) printf("Yes\n");
            else printf("No\n");
        }        
    }
    return 0;
}