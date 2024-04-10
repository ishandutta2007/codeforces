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

bool dead[2048];
char c;
int n, k;
int main(){
    cin >> n >> k;
    int block = max(1, k/2);
    for(int i = 1;i < n/block;i++){
        int now = i;
        int move = 1;
        cout << "R" << endl;
        do{
            for(int j = 0;j < block;j++){
                int nxt = now * block + j;
                if(dead[nxt])continue;
                cout << "? " << nxt + 1 << endl;
                cin >> c;
                if(c == 'Y')dead[nxt] = true;
            }
            if(move % 2)now -= move;
            else now += move;
            move++;
        }while(0 <= now && now < n/block);
    }
    int ans = 0;
    for(int i = 0;i < n;i++)ans += !dead[i];
    cout << "! " << ans << endl;
    return 0;
}