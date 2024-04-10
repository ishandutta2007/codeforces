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

int n, q, r, c;
int cnt;
int block[2][110000];

int calc(int x, int y){
    if(!block[x][y])return 0;
    return block[!x][y-1] + block[!x][y] + block[!x][y+1];
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0;i < q;i++){
        scanf("%d%d", &r, &c);
        r--,c+=2;
        for(int k = -3;k <= 3;k++){
            cnt -= calc(0, c + k);
        }
        
        block[r][c] ^= 1;
        for(int k = -3;k <= 3;k++){
            cnt += calc(0, c + k);
        }
        
        if(cnt == 0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}