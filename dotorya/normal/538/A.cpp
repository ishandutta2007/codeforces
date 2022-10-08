/*#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
const ll UND = 1000000000000000001L;

class Point {
public:
    Point() {
        Point(UND, UND, UND);
    }
    Point(ll a, ll b, ll c) {
        x = a, y = b, t = c;
    }
    bool isNull() {
        if(x == UND) return true;
        else return false;
    }
    ll x, y, t;
} d[2000050];

vector <Point> toChk;
vector <char> ANS;

int main() {
    int N, L, i, j;
    ll t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    ll dx = UND, dy = UND;
    scanf("%d %d", &N, &L);

    d[0] = Point(0,0,0);
    for(i = 1; i < L; i++) d[i] = Point(UND, UND, UND);
    for(i = 1; i <= N; i++) {
        scanf("%lld %lld %lld", &t1, &t2, &t3);
        t4 = t1%L;
        if(!d[t4].isNull()) {
            t5 = d[t4].t, t6 = d[t4].x, t7 = d[t4].y;
            t8 = (d[t4].t - t1) / L;
            if((t2-t6)%t8 != 0 || (t3-t7)%t8 != 0) break;
            else {
                t9 = (t6-t2)/t8;
                t10 = (t7-t3)/t8;
                if(dx != UND) {
                    if(dx != t9 || dy != t10) break;
                }
                else {
                    dx = t9, dy = t10;
                }
            }
        }
        else {
            d[t4].t = t1, d[t4].x = t2, d[t4].y = t3;
        }
    }
    if(i != N+1) {
        printf("NO");
        return 0;
    }

    if(dx != UND) {
        if(abs(dx)+abs(dy) > L) {
            printf("NO");
            return 0;
        }
        Point st = Point(UND, UND, UND);
        for(i = 0; i < L; i++) {
            if(d[i].x == UND) continue;
            d[i].x -= (d[i].t / L) * dx;
            d[i].y -= (d[i].t / L) * dy;
            d[i].t %= L;
            toChk.push_back(d[i]);
            if(st.isNull()) st = d[i];
        }
        toChk.push_back(st);

        for(i = 0; i < toChk.size()-1; i++) {
            t1 = toChk[i+1].x - toChk[i].x;
            t2 = toChk[i+1].y - toChk[i].y;
            t3 = toChk[i+1].t - toChk[i].t;
            int chk = 0;
            if(t3 < 0) {
                t3 += L;
                chk = 1;
            }
            t1 += dx * chk;
            t2 += dy * chk;
            if(abs(t1) + abs(t2) > t3) {
                printf("NO");
                return 0;
            }
            if(t1+t2+t3 % 2 == 1) {
                printf("NO");
                return 0;
            }
            if(t1 > 0) {
                for(j = 1; j <= t1; j++) ANS.push_back('R');
                t3 -= t1;
            }
            else {
                for(j = 1; j <= -t1; j++) ANS.push_back('L');
                t3 += t1;
            }
            if(t2 > 0) {
                for(j = 1; j <= t2; j++) ANS.push_back('U');
                t3 -= t2;
            }
            else {
                for(j = 1; j <= -t2; j++) ANS.push_back('D');
                t3 += t2;
            }
            if(t3 % 2 == 1) {
                printf("NO");
                return 0;
            }
            for(j = 1; j <= t3/2; j++) {
                ANS.push_back('U');
                ANS.push_back('D');
            }
        }
        if(i == toChk.size()-1) {
            for(i = 0; i < ANS.size(); i++) printf("%c", ANS[i]);
            return 0;
        }
        else {
            printf("NO");
            return 0;
        }
    }
    return 0;
}*/

#include <stdio.h>
char d[105];
char s[15] = "CODEFORCES";
int main() {
    int L;
    scanf("%s", d);
    for(L = 0; d[L] != 0; L++);
    if(L < 10) {
        printf("NO");
        return 0;
    }
    int cut_L = L-10, i;
    for(i = 0; i <= 10; i++) {
        int st = 0, j;
        for(j = 0; j < i; j++) {
            if(d[j] != s[st]) break;
            st++;
        }
        if(j < i) continue;
        for(j = L-10+i; j < L; j++) {
            if(d[j] != s[st]) break;
            st++;
        }
        if(j < L) continue;
        else break;
    }
    if(i == 11) printf("NO");
    else printf("YES");
    return 0;
}