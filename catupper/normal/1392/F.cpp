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

Int sq[1100000];
Int n;
Int a[1100000];
vector<P> slants;

int main(){
    scanf("%lld", &n);
    for(int i = 0;i < n;i++){
        Int h;
        scanf("%lld", &h);
        while(true){
            if(slants.empty()){
                slants.push_back({h,h});
                break;
            }
            if(slants.size() == 1){
                Int a = slants.back().first;
                Int b = slants.back().second;
                Int w = b-a+1;
                Int all = (a+b)*w / 2 + h;
                w++;
                Int l = (all - w * (w - 1) / 2) / w;
                Int m = (all - w * (w - 1) / 2) % w;
                slants.clear();
                if(m)slants.push_back({l+1, l + m});
                slants.push_back({l + m, l+w-1});
                break;
            }
            Int a = slants.back().first;
            Int b = slants.back().second;
            Int w = b - a + 1;
            if(h >= b+1+w){
                h -= w;
                slants.pop_back();
                slants.back().second = b+1;
            }
            else{
                Int m = h - (b+1);
                slants[slants.size() - 2].second += m;
                slants.back().first += m;
                slants.back().second++;
                break;
            }
        }
    }
    for(auto p:slants){
        for(Int i = p.first;i <= p.second;i++){
            printf("%lld ", i);
        }
    }
    puts("");
    return 0;
}