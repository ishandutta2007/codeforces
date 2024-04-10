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


int neighbor[255][255];
int a[255][255];
int n, m;
int pos[255*255];

vector<P> oks;

void put_num(int x, int y, int val){
    a[x][y] = val;
    if(x+1 < n){
        neighbor[x+1][y]++;
        if(neighbor[x+1][y] == 2)oks.push_back(P(x+1,y));
    }
    if(x-1 >= 0){
        neighbor[x-1][y]++;
        if(neighbor[x-1][y] == 2)oks.push_back(P(x-1,y));
    }
    if(y+1 < m){
        neighbor[x][y+1]++;
        if(neighbor[x][y+1] == 2)oks.push_back(P(x,y+1));
    }
    if(y-1 >= 0){
        neighbor[x][y-1]++;
        if(neighbor[x][y-1] == 2)oks.push_back(P(x,y-1));
    }
}

void put_somewhere(int val){
    while(true){
        auto p = oks.back();oks.pop_back();
        int x =p.first, y = p.second;
        if(a[x][y] != -1)continue;
        put_num(x, y, val);       
        return;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        int tmp = 0;
        for(int j = 0;j < m;j++)tmp = max(tmp, a[i][j]);
        pos[tmp] += 1;
    }
    for(int j = 0;j < m;j++){
        int tmp = 0;
        for(int i = 0;i < n;i++)tmp = max(tmp, a[i][j]);
        pos[tmp] += 2;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            a[i][j] = -1;
        }
    }
    int ip = -1, jp = -1;
    for(int i = n * m;i >= 1;i--){
        if(pos[i] == 3)put_num(++ip,++jp,i);
        if(pos[i] == 2)put_num(ip,++jp,i);
        if(pos[i] == 1)put_num(++ip,jp,i);
        if(pos[i] == 0)put_somewhere(i);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    return 0;
}