#include <stdio.h>
#include <vector>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007;
struct data {
    data() {
        data(0,0,0);
    }
    data(int a, int b, int c) {
        x = a, y = b, chk = c;
    }
    int x, y, chk; // chk : 0 x, 1 o
};
void point_reverse(int &a, int &b, int c) {
    int tmp = b-(c+1-a);
    a = a-tmp;
    b = b-tmp;
    return;
}
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
vector <data> even, odd;
int parent_odd[100050][2];
int parent_even[100050][2];
int find_parent_odd(int x) {
    if(parent_odd[x][0] == parent_odd[parent_odd[x][0]][0]) return parent_odd[x][0];
    int tmp = parent_odd[x][0];
    parent_odd[x][0] = find_parent_odd(parent_odd[x][0]);
    parent_odd[x][1] = (parent_odd[tmp][1]^parent_odd[x][1]);
    return parent_odd[x][0];
}
int find_parent_even(int x) {
    if(parent_even[x][0] == parent_even[parent_even[x][0]][0]) return parent_even[x][0];
    int tmp = parent_even[x][0];
    parent_even[x][0] = find_parent_even(parent_even[x][0]);
    parent_even[x][1] = (parent_even[tmp][1]^parent_even[x][1]);
    return parent_even[x][0];
}
int main() {
    int N, M, i, j, t1, t2, t3, t4, t5, even_size, odd_size;
    char c;
    scanf("%d %d", &N, &M);
    odd_size = N/2;
    even_size = N-odd_size;
    if(N == 1) {
        printf("1");
        return 0;
    }
    for(i = 1; i <= M; i++) {
        scanf("%d %d %c", &t1, &t2, &c);
        if(c == 'o') t3 = 1;
        else t3 = 0;
        if(t1+t2 > N+1) point_reverse(t1, t2, N);
        if(t1 > t2) swap(t1, t2);
        if((t1+t2)%2 == 0) {
            if(t1+t2 == N+1 || t1+t2 == N) even.push_back(data(even_size+1-t1, -1, t3));
            else even.push_back(data((t1+t2)/2+1, (t1+t2)/2+1-t1, t3));
        }
        else {
            if(t1+t2 == N+1 || t1+t2 == N) odd.push_back(data(odd_size+1-t1, -1, t3));
            else odd.push_back(data((t1+t2)/2+1, (t1+t2)/2+1-t1, t3));
        }
    }
    ll ans = 1;
    for(i = 1; i <= odd_size; i++) {
        parent_odd[i][0] = i;
        parent_odd[i][1] = -1;
    }
    for(i = 1; i <= even_size; i++) {
        parent_even[i][0] = i;
        parent_even[i][1] = -1;
    }
    for(i = 0; i < odd.size(); i++) {
        t1 = odd[i].x, t2 = odd[i].y, t3 = odd[i].chk;
        if(t2 == -1) {
            t4 = find_parent_odd(t1);
            if(t4 == t1) {
                if(parent_odd[t1][1] == -1) {
                    parent_odd[t1][1] = t3;
                    continue;
                }
                if(parent_odd[t1][1] != t3) break;
            }
            else {
                if(parent_odd[t4][1] == -1) {
                    parent_odd[t4][1] = (t3^parent_odd[t1][1]);
                    continue;
                }
                if(parent_odd[t4][1] != (t3^parent_odd[t1][1])) break;
            }
        }
        else {
            t4 = find_parent_odd(t1);
            t5 = find_parent_odd(t2);
            if(t4 == t5) {
                if(t1 == t4) {
                    if(parent_odd[t2][1] != t3) break;
                    continue;
                }
                if(t2 == t4) {
                    if(parent_odd[t1][1] != t3) break;
                    continue;
                }
                if((parent_odd[t1][1] ^ parent_odd[t2][1]) != t3) break;
                continue;
            }
            if(t1 != t4) t3 = (t3^parent_odd[t1][1]);
            if(t2 != t5) t3 = (t3^parent_odd[t2][1]);
            if(parent_odd[t4][1] != -1) {
                if(parent_odd[t5][1] == -1) swap(t4, t5);
                else {
                    if((parent_odd[t4][1]^parent_odd[t5][1]) != t3) break;
                }
            }
            parent_odd[t4][0] = t5;
            parent_odd[t4][1] = t3;
        }
    }
    if(i != odd.size()) {
        printf("0");
        return 0;
    }
    for(i = 0; i < even.size(); i++) {
        t1 = even[i].x, t2 = even[i].y, t3 = even[i].chk;
        if(t2 == -1) {
            t4 = find_parent_even(t1);
            if(t4 == t1) {
                if(parent_even[t1][1] == -1) {
                    parent_even[t1][1] = t3;
                    continue;
                }
                if(parent_even[t1][1] != t3) break;
            }
            else {
                if(parent_even[t4][1] == -1) {
                    parent_even[t4][1] = (t3^parent_even[t1][1]);
                    continue;
                }
                if(parent_even[t4][1] != (t3^parent_even[t1][1])) break;
            }
        }
        else {
            t4 = find_parent_even(t1);
            t5 = find_parent_even(t2);
            if(t4 == t5) {
                if(t1 == t4) {
                    if(parent_even[t2][1] != t3) break;
                    continue;
                }
                if(t2 == t4) {
                    if(parent_even[t1][1] != t3) break;
                    continue;
                }
                if((parent_even[t1][1] ^ parent_even[t2][1]) != t3) break;
                continue;
            }
            if(t1 != t4) t3 = (t3^parent_even[t1][1]);
            if(t2 != t5) t3 = (t3^parent_even[t2][1]);
            if(parent_even[t4][1] != -1) {
                if(parent_even[t5][1] == -1) swap(t4, t5);
                else {
                    if((parent_even[t4][1]^parent_even[t5][1]) != t3) break;
                }
            }
            parent_even[t4][0] = t5;
            parent_even[t4][1] = t3;
        }
    }
    if(i != even.size()) {
        printf("0");
        return 0;
    }
    for(i = 1; i <= odd_size; i++) if(parent_odd[i][1] == -1) ans = (ans*2)%MOD;
    for(i = 1; i <= even_size; i++) if(parent_even[i][1] == -1) ans = (ans*2)%MOD;
    printf("%lld", ans);
    return 0;
}