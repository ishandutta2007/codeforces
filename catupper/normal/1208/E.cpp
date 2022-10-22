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
 
multiset<Int> ms;
Int n, w, l;
Int a[1080000];
Int ans[1080000];
Int bit[1080000];

void add(Int pos, Int val){
    pos++;
    while(pos < 1080000){
        bit[pos] +=val;
        pos += pos & -pos;
    }
}

Int sum(Int pos){
    pos++;
    Int res = 0;
    while(pos){
        res += bit[pos];
        pos -= pos & -pos;
    }
    return res;
}

void add2(Int l, Int r, Int val){
    l++,r++;
    add(l, val);
    add(r, -val);
}

Int sum2(Int pos){
    pos++;
    return sum(pos);
}
int main(){
    cin >> n >> w;
    for(Int i = 0;i < n;i++){
        cin >> l;
        for(int i = 0;i < l;i++)cin >> a[i];

        if(w < l * 2 + 10){
            Int lt = 0;
            ms.clear();
            for(Int rt = 0;rt < w;rt++){
                if(rt < l){
                    ms.insert(a[rt]);
                }
                while(lt < rt - (w - l)){
                    ms.erase(ms.find(a[lt]));
                    lt++;
                }
                Int adder = *ms.rbegin();
                if(rt < w - l || rt >= l)
                    adder = max(adder , 0LL);
                ans[rt] += adder;
            }
        }
        else{
            Int tmax = 0;
            for(int i = 0;i < l;i++){
                tmax = max(tmax, a[i]);
                add2(i, i+1,tmax);
            }
            tmax = 0;
            for(int i = l-1;i >= 0;i--){
                tmax = max(tmax, a[i]);
                add2(w-l+i, w-l+i+1, tmax);
            }
            add2(l, w-l, tmax);
        }
    }
    for(int i = 0;i < w;i++)printf("%lld ", ans[i] + sum2(i));
    printf("\n");
    return 0;
}