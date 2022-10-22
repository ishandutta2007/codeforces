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


int n, k;
char digit[10];
int bin[2200];
int pop_count[1<<8];
bool ok[2200][2200];

int num[] = {0b1110111,
             0b0010010,
             0b1011101,
             0b1011011,
             0b0111010,
             0b1101011,
             0b1101111,
             0b1010010,
             0b1111111,
             0b1111011};


int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1;i < (1 << 8);i++)pop_count[i] = pop_count[i/2] + i % 2;
    for(int i = 0;i < n;i++){
        scanf(" %s", digit);
        bin[i] = 0;
        for(int j = 0;j < 7;j++){
            bin[i] *= 2;
            if(digit[j] != '0')bin[i]++;
        }

    }
    ok[n][0] = true;

    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j <= k;j++){
            for(int d = 0;d <= 9;d++){
                if((num[d] & bin[i]) != bin[i])continue;
                int pc =pop_count[num[d] ^ bin[i]];
                if(j >= pc)ok[i][j] |= ok[i+1][j - pc]; 
            }
        }
    }
    if(!ok[0][k]){
        puts("-1");
        return 0;
    }
    for(int i = 0;i < n;i++){
        for(int d = 9;d >= 0;d--){
            if((num[d] & bin[i]) != bin[i])continue;
            int pc =pop_count[num[d] ^ bin[i]];
            if(k >= pc && ok[i+1][k-pc]){
                printf("%d", d);
                k -= pc;
                break;
            }
        }
    }
    puts("");

    return 0;
}