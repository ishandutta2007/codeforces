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


int n, k;
int main(){
    cin >> n >> k;
    if(k == 1){
        printf("1");
        for(int i = 1;i < n;i++)printf("0");
        printf("\n");
    }
    else{
        int x = (n - (k-2))/2;
        for(int i = 0;i < n;i++){
            if(i % x)printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}