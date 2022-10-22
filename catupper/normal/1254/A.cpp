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

string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char field[110][110];
char ans[110][110];
Int t;

void solve(){
    int r, c, k;
    int sum = 0;
    scanf("%d%d%d", &r, &c, &k);
    for(int i = 0;i < r;i++){
        scanf("%s", field[i]);
        for(int j = 0;j < c;j++)if(field[i][j] == 'R')sum++;
        ans[i][c] = 0;
    }
    int id = 0;
    int cnt = 0;
    for(int i = 0;i < r;i++){
        if(i % 2){
            for(int j = 0;j < c;j++){
                ans[i][j] = chars[id];
                if(field[i][j] == 'R')cnt++;
                if(id < k-1 && cnt == sum / k + (id < sum % k)){
                    cnt = 0;
                    id++;
                }
            }
        }
        else{
            for(int j = c-1;j >= 0;j--){
                ans[i][j] = chars[id];
                if(field[i][j] == 'R')cnt++;
                if(id < k-1 && cnt == sum / k + (id < sum % k)){
                    cnt = 0;
                    id++;
                }
            }
        }
        printf("%s\n", ans[i]);
    }
}

int main(){
    cin >> t;
    while(t--)solve();
    return 0;
}