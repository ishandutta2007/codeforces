#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
map <int, int> isChanged;

vector <int> IT_val;
vector <pair <int, int>> IT_val2;
int rev_chk[200050];
const int IT_MAX = 262144;  
int it[IT_MAX*2];

void update(int node) {
    it[node] = 1;
    while(node != 1) {
        node /= 2;
        it[node] = it[2*node]+it[2*node+1];
    }
    return;
}
int get_sum(int st, int en) {
    if(st>en) return 0;
    int t = 0;
    if(st == en) return it[st];
    if(st % 2 == 1) {
        t += it[st];
        st++;
    }
    if(st == en) return t+it[st];
    if(en % 2 == 0) {
        t += it[en];
        en--;
    }
    return t+get_sum(st/2, en/2);
}

vector <int> BI;

int getBetween(int a, int b) {
    int ans = -1, ans2 = -1, st, en, mi;
    st = 0, en = BI.size()-1;
    while(st <= en) {
        mi = (st+en)/2;
        if(BI[mi] < a) {
            ans = mi;
            st = mi+1;
        }
        else en = mi-1;
    }
    st = 0, en = BI.size()-1;       
    while(st <= en) {
        mi = (st+en)/2;
        if(BI[mi] <= b) {
            ans2 = mi;
            st = mi+1;
        }
        else en = mi-1;
    }
    return ans2-ans;
}

int main() {
    int N, i, t1, t2;
    long long ANS = 0;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d %d", &t1, &t2);
        if(isChanged.count(t1) == 0) isChanged.insert(pair <int, int> (t1, t1));
        if(isChanged.count(t2) == 0) isChanged.insert(pair <int, int> (t2, t2));
        swap(isChanged[t1], isChanged[t2]);
    }

    // Index tree
    int chk = 0;
    for(map <int, int>::iterator t = isChanged.begin(); t != isChanged.end(); t++) {
        IT_val.push_back(t->second);
        IT_val2.push_back(pair <int, int> (t->second, chk));
        chk++;
    }
    sort(IT_val2.begin(), IT_val2.end());
    for(i = 0; i < IT_val2.size(); i++) rev_chk[IT_val2[i].second] = i;
    for(i = IT_val2.size()-1; i >= 0; i--) {
        ANS += get_sum(IT_MAX, IT_MAX+rev_chk[i]-1);
        update(IT_MAX+rev_chk[i]);
    }

    // Binary Search
    for(map <int, int>::iterator t = isChanged.begin(); t != isChanged.end(); t++) BI.push_back(t->first);

    for(map <int, int>::iterator t = isChanged.begin(); t != isChanged.end(); t++) {
        int a = t->first, b = t->second;
        if(a-1 > b) ANS += a-b-1-getBetween(b+1, a-1);
        if(a+1 < b) ANS += b-a-1-getBetween(a+1, b-1);
    }

    printf("%lld", ANS);
    return 0;
}