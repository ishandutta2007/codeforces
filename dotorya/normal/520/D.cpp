#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> parent[100050];
vector <int> son[100050];
vector <int> ANS;
int M;
int removed_chk[100050];
int son_cnt[100050];
struct data {
    data() {
        data(0,0,0);
    }
    data(int a, int b, int c) {
        x = a, y = b, chk = c;
    }
    int x, y, chk;
    bool operator < (const data & l) const {
        if(x != l.x) return x < l.x;
        else return y < l.y;
    }
    bool operator == (const data & l) const {
        return x == l.x && y == l.y;
    }
} d[100050];
struct data2 {
    data2() {
        data2(0,0);
    }
    data2(int a, int b) {
        n = a, sorted_n = b;
    }
    int n, sorted_n;
    bool operator < (const data2 & l) const {
        return n<l.n;
    }
};
priority_queue <data2> min_heap;
priority_queue <data2> max_heap;
int bin_search(data tmp) {
    int st = 0, en = M-1, mi;
    while(st <= en) {
        mi = (st+en)/2;
        if(tmp == d[mi]) return mi;
        if(tmp < d[mi]) {
            en = mi-1;
        }
        else st = mi+1;
    }
    return -1;
}
int main() {
    int i, t1, t2, j, k;
    scanf("%d", &M);
    for(i = 0; i < M; i++) {
        scanf("%d %d", &d[i].x, &d[i].y);
        d[i].chk = i;
    }
    sort(d, d+M);
    for(i = 0; i < M; i++) {
        data t_data;
        t_data = data(d[i].x-1, d[i].y+1, -1);
        t2 = bin_search(t_data);
        if(t2 != -1) parent[i].push_back(t2);
        t_data = data(d[i].x, d[i].y+1, -1);
        t2 = bin_search(t_data);
        if(t2 != -1) parent[i].push_back(t2);
        t_data = data(d[i].x+1, d[i].y+1, -1);
        t2 = bin_search(t_data);
        if(t2 != -1) parent[i].push_back(t2);
        t_data = data(d[i].x-1, d[i].y-1, -1);
        t2 = bin_search(t_data);
        if(t2 != -1) {
            son[i].push_back(t2);
            son_cnt[i]++;
        }
        t_data = data(d[i].x, d[i].y-1, -1);
        t2 = bin_search(t_data);
        if(t2 != -1) {
            son[i].push_back(t2);
            son_cnt[i]++;
        }
        t_data = data(d[i].x+1, d[i].y-1, -1);
        t2 = bin_search(t_data);
        if(t2 != -1) {
            son[i].push_back(t2);
            son_cnt[i]++;
        }
    }
    for(i = 0; i < M; i++) {
        for(j = 0; j < parent[i].size(); j++) {
            if(son_cnt[parent[i][j]] == 1) break;
        }
        if(j == parent[i].size()) {
            max_heap.push(data2(d[i].chk, i));
            min_heap.push(data2(-d[i].chk, i));
        }
    }
    for(i = 1; i <= M; i++) {
        if(i%2 == 1) {
            while(!max_heap.empty()) {
                t1 = max_heap.top().sorted_n;
                t2 = max_heap.top().n;
                max_heap.pop();
                if(removed_chk[t1] == 1) continue;
                for(j = 0; j < parent[t1].size(); j++) {
                    if(removed_chk[parent[t1][j]] == 1) continue;
                    if(son_cnt[parent[t1][j]] == 1) break;
                }
                if(j == parent[t1].size()) {
                    ANS.push_back(t2);
                    removed_chk[t1] = 1;
                    for(j = 0; j < parent[t1].size(); j++) son_cnt[parent[t1][j]]--;
                    for(j = 0; j < son[t1].size(); j++) {
                        t2 = son[t1][j];
                        for(k = 0; k < parent[t2].size(); k++) {
                            if(removed_chk[parent[t2][k]] == 1) continue;
                            if(son_cnt[parent[t2][k]] == 1) break;
                        }
                        if(k == parent[t2].size()) {
                            max_heap.push(data2(d[t2].chk, t2));
                            min_heap.push(data2(-d[t2].chk, t2));
                        }
                    }
                    break;
                }
            }
        }
        else {
            while(!min_heap.empty()) {
                t1 = min_heap.top().sorted_n;
                t2 = -min_heap.top().n;
                min_heap.pop();
                if(removed_chk[t1] == 1) continue;
                for(j = 0; j < parent[t1].size(); j++) {
                    if(removed_chk[parent[t1][j]] == 1) continue;
                    if(son_cnt[parent[t1][j]] == 1) break;
                }
                if(j == parent[t1].size()) {
                    ANS.push_back(t2);
                    removed_chk[t1] = 1;
                    for(j = 0; j < parent[t1].size(); j++) son_cnt[parent[t1][j]]--;
                    for(j = 0; j < son[t1].size(); j++) {
                        t2 = son[t1][j];
                        for(k = 0; k < parent[t2].size(); k++) {
                            if(removed_chk[parent[t2][k]] == 1) continue;
                            if(son[parent[t2][k]].size() == 1) break;
                        }
                        if(k == parent[t2].size()) {
                            max_heap.push(data2(d[t2].chk, t2));
                            min_heap.push(data2(-d[t2].chk, t2));
                        }
                    }
                    break;
                }
            }
        }
    }
    long long print_ans = 0;
    for(i = 0; i < ANS.size(); i++) {
        print_ans *= M;
        print_ans += ANS[i];
        print_ans %= 1000000009;
    }
    printf("%lld", print_ans);
    return 0;
}