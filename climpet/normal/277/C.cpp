#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int,int> pii;

struct info{
    int len;
    vector<pii> v;

    info(): len(-1) {}
};

typedef map<int,info> map_info;

int nim(map_info &mp, int a, int b){
    map_info::iterator it;
    int r = 0;

    if(mp.size() + 1 < a){
        int k;
        for(k = 1; mp.count(k); ++k);
        mp[k];
    }

    for(it = mp.begin(); it != mp.end(); ++it){
        vector<pii> &v = it->second.v;
        v.push_back(pii(b, 0));
        sort(v.begin(), v.end());
        int s = 0, c = 0, p = 0;
        for(int i = 0; i < v.size(); ++i){
            if(c == 0){ s += v[i].first - p; }
            p = v[i].first;
            c += v[i].second;
        }
        it->second.len = s;
        r ^= s;
    }

    if((a - mp.size()) % 2 == 0){
        r ^= b;
    }

    return r;
}


int length(const vector<pii> &v, int len){
    int s = 0, c = 0, p = 0;
    for(int i = 0; ; ++i){
        if(c == 0){
            s += v[i].first - p;
            if(s >= len){
                int d = s - len;
                return v[i].first - d;
            }
        }
        p = v[i].first;
        c += v[i].second;
    }
}


int main(){
    int n, m, k;
    int xb, yb, xe, ye;
    map_info mx, my;

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; ++i){
        scanf("%d%d%d%d", &xb, &yb, &xe, &ye);
        if(xb == xe){
            if(yb > ye){ swap(yb, ye); }
            mx[xb].v.push_back(pii(yb, 1));
            mx[xb].v.push_back(pii(ye, -1));
        }
        else{
            if(xb > xe){ swap(xb, xe); }
            my[yb].v.push_back(pii(xb, 1));
            my[yb].v.push_back(pii(xe, -1));
        }
    }

    int r = nim(mx, n, m) ^ nim(my, m, n);
    if(r == 0){
        puts("SECOND");
        return 0;
    }

    puts("FIRST");
    int bit;
    for(bit = 1 << 30; !(r & bit); bit >>= 1);

    map_info::iterator it;
    for(it = mx.begin(); it != mx.end(); ++it){
        if(it->second.len & bit){
            int k = it->second.len - (r ^ it->second.len);
            int to = length(it->second.v, k);
            int x = it->first;
            
            printf("%d 0 %d %d\n", x, x, to);
            return 0;
        }
    }
    
    for(it = my.begin(); ; ++it){
        if(it->second.len & bit){
            int k = it->second.len - (r ^ it->second.len);
            int to = length(it->second.v, k);
            int y = it->first;
            
            printf("0 %d %d %d\n", y, to, y);
            return 0;
        }
    }
}