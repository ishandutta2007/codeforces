#include <stdio.h>
#include <vector>
using namespace std;
vector <int> conn[100050];
vector <int> rev_conn[100050];
vector <int> tmp;
int rev_conn_cnt[100050];
int N;
int group[100050];
int queue[100050];
void input() {
    int i, t1, t2, M;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        rev_conn[t2].push_back(t1);
        rev_conn_cnt[t2]++;
    }
    return;
}
void get_group() {
    int i, j, st, en, t, c = 0, ANS = 0;
    for(i = 1; i <= N; i++) {
        if(group[i] != 0) continue;
        tmp.clear();
        c++;
        group[i] = c;
        queue[1] = i;
        st = 1, en = 2;
        while(st < en) {
            t = queue[st];
            tmp.push_back(t);
            for(j = 0; j < conn[t].size(); j++) {
                if(group[conn[t][j]] != 0) continue;
                queue[en++] = conn[t][j];
                group[conn[t][j]] = c;
            }
            for(j = 0; j < rev_conn[t].size(); j++) {
                if(group[rev_conn[t][j]] != 0) continue;
                queue[en++] = rev_conn[t][j];
                group[rev_conn[t][j]] = c;
            }
            st++;
        }
        if(tmp.size() == 1) continue;
        ANS += tmp.size();
        st = en = 1;
        for(i = 0; i < tmp.size(); i++) {
            if(rev_conn_cnt[tmp[i]] == 0) queue[en++] = tmp[i];
        }
        while(st < en) {
            t = queue[st];
            for(j = 0; j < conn[t].size(); j++) {
                rev_conn_cnt[conn[t][j]]--;
                if(rev_conn_cnt[conn[t][j]] == 0) {
                    queue[en++] = conn[t][j];
                }
            }
            st++;
        }
        if(tmp.size()+1 == st) ANS--;

    }
    printf("%d", ANS);
    return;
}
        
int main() {
    input();
    get_group();
    return 0;
}