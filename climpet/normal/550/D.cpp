#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int k;
    scanf("%d", &k);
    if(k & 1){
        vector<pair<int,int> > v;
        int u = 2 * k - 3;
        for(int i = 0; i + 1 < k; ++i){
            v.emplace_back(0, i + 1);
            v.emplace_back(1, i + k);
        }
        for(int i = 0; i < u; ++i){
            for(int d = 1; d * 2 < k; ++d){
                v.emplace_back(i + 2, (i + d) % u + 2);
            }
        }

        printf("YES\n%d %d\n1 2\n", 2 * u + 4, (int)v.size() * 2 + 1);
        for(const auto &p : v)
        for(int i = 1; i <= 2; ++i){
            printf("%d %d\n", p.first * 2 + i, p.second * 2 + i);
        }
    }
    else{
        puts("NO");
    }
}