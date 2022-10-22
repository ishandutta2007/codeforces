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
int m[220000];
int c[220000];

Int test_case_num = 0;
vector<Int> test_case[220000];

set<P> test_cases;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n;i++){
        scanf("%d", m + i);
    }
    for(int i = 1;i <= k;i++){
        scanf("%d", c + i);
    }

    sort(m, m + n);

    for(int i = n-1;i >= 0;i--){
        int max_size = c[m[i]]-1;
        auto it = test_cases.upper_bound(P(max_size, INF));
        if(it == test_cases.begin()){
            test_case[test_case_num].push_back(m[i]);
            test_cases.insert(P(1, test_case_num));
            test_case_num++;
        }
        else{
            it--;
            int ind = it->second;
            test_case[ind].push_back(m[i]);
            test_cases.erase(it);
            test_cases.insert(P(test_case[ind].size(),ind));
        }
    }

    printf("%lld\n", test_case_num);
    for(int i = 0;i < test_case_num;i++){
        printf("%d", (int)test_case[i].size());
        for(auto elem:test_case[i]){
            printf(" %lld", elem);
        }
        puts("");
    }
    
    return 0;
}