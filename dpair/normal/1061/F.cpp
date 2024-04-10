/*
    author: DPair
    language: C++

    description:
    
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

namespace My_Rand{
    int index, MT[624];
    inline void srand(int seed){
        index = 0;
        MT[0] = seed;
        for (register int i = 1;i < 624;i ++){
            int t = 1812433253 * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i;
            MT[i] = t & 0xffffffff;
        }
    }
    inline void rotate(){
        for (register int i = 0;i < 624;i ++){
            int tmp = (MT[i] & 0x80000000) + (MT[(i + 1) % 624] & 0x7fffffff);
            MT[i] = MT[(i + 397) % 624] ^ (tmp >> 1);
            if(tmp & 1) MT[i] ^= 2567483615;
        }
    }
    inline int rand(){
        if(!index) rotate();
        int ret = MT[index];
        ret = ret ^ (ret >> 11);
        ret = ret ^ ((ret << 7) & 2636928640);
        ret = ret ^ ((ret << 15) & 4022730752);
        ret = ret ^ (ret >> 18);
        index = (index + 1) % 624;
        return ret;
    }
} // namespace My_Rand
set <int> s;
int dep = 1;
char res[5];
vector <int> vec;
inline void getans(int u, int v){//(u, v)
    int tot = s.size();
    int num = My_Rand :: rand() % tot;
    auto it = s.begin();
    while(num --) ++ it;
    int w = *it;
    for (register int i = 1;i <= n;i ++){
        printf("? %d %d %d\n", u, i, w);
        fflush(stdout);
        scanf("%s", res);
        if(res[0] == 'Y') vec.push_back(i);
    }
    if(vec.size() == dep) {
        printf("! %d\n", w);
        fflush(stdout);
        return ;
    }
    if(vec.size() < dep){
        while(!vec.empty()) {
            s.erase(vec.back());
            vec.pop_back();
        }
        getans(u, v);
    }
    if(vec.size() > dep){
        s.clear();
        while(!vec.empty()) {
            s.insert(vec.back());
            vec.pop_back();
        }
        getans(u, v);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    int num = 1, tot = 1;
    for (;tot < n;dep ++){
        num *= k;
        tot += num;
    }
    My_Rand :: srand(time(NULL));
    while(1){
        int u = My_Rand :: rand() % n + 1;
        int v = My_Rand :: rand() % n + 1;
        while(u == v){
            u = My_Rand :: rand() % n + 1;
            v = My_Rand :: rand() % n + 1;
        }
        for (register int i = 1;i <= n;i ++){
            printf("? %d %d %d\n", u, i, v);
            fflush(stdout);
            scanf("%s", res);
            if(res[0] == 'Y') s.insert(i);
        }
        if(s.size() == (dep << 1) - 1){
            getans(u, v);
            return 0;
        }
        s.clear();
    }
}