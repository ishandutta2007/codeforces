#include <stdio.h>
#include <vector>
using namespace std;
int N;
char t[4];
vector <int> conn[4000];
vector <int> ANS;
vector <char> ANS2;
int chk[4000][2];
int characterToNum(char c1, char c2) {
    int t1, t2;
    if(c1 >= '0' && c1 <= '9') t1 = c1-'0';
    if(c1 >= 'a' && c1 <= 'z') t1 = c1-'a'+10;
    if(c1 >= 'A' && c1 <= 'Z') t1 = c1-'A'+36;
    if(c2 >= '0' && c2 <= '9') t2 = c2-'0';
    if(c2 >= 'a' && c2 <= 'z') t2 = c2-'a'+10;
    if(c2 >= 'A' && c2 <= 'Z') t2 = c2-'A'+36;
    return t1*62+t2;
}
char numToCharacter(int n) {
    if(n < 10) return n+'0';
    if(n < 36) return n-10+'a';
    return n-36+'A';
}
void input() {
    int i, t1, t2;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%s", t);
        t1 = characterToNum(t[0], t[1]);
        t2 = characterToNum(t[1], t[2]);
        conn[t1].push_back(t2);
        chk[t1][0]++, chk[t2][1]++;
    }
    return;
}
void DFS(int node) {
    int t1;
    while(!conn[node].empty()) {
        t1 = conn[node].back();
        conn[node].pop_back();
        DFS(t1);
    }
    ANS.push_back(node);
    return;
}
void get_ans() {
    int st = -1, en = -1, t_st, i;
    for(i = 0; i < 3844; i++) {
        if(chk[i][0] - chk[i][1] >= 2 || chk[i][0] - chk[i][1] <= -2) break;
        if(chk[i][0] != 0) t_st = i;
        if(chk[i][0] - chk[i][1] == 1) {
            if(st != -1) break;
            st = i;
        }
        if(chk[i][0] - chk[i][1] == -1){
            if(en != -1) break;
            en = i;
        }
    }
    if(i != 3844) {
        printf("NO");
        return;
    }
    if(st == -1) st = t_st;
    DFS(st);
    char tmp = numToCharacter(ANS.back()/62);
    ANS2.push_back(tmp);
    tmp = numToCharacter(ANS.back()%62);
    ANS2.push_back(tmp);
    ANS.pop_back();
    while(!ANS.empty()) {
        tmp = numToCharacter(ANS.back()%62);
        ANS2.push_back(tmp);
        ANS.pop_back();
    }
    if(ANS2.size() != N+2) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for(i = 0; i < ANS2.size(); i++) printf("%c", ANS2[i]);
    return;
}
int main() {
    input();
    get_ans();
    return 0;
}