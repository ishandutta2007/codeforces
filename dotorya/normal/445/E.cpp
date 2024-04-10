#include <stdio.h>
const int MX = 262144;
typedef long long ll;
struct data {
    data() {
        data(0,123456789,0,-1,0,0,0);
    }
    data(ll a, ll b, ll c, ll d, ll e, ll f, ll g) {
        max = a, min = b, sum = c, color = d, color_sum = e, update_color_sum = f, c_color = g;
    }
    ll max, min, sum, color, c_color, color_sum, update_color_sum;
};
data it[MX*2+50];
ll MAX(ll a, ll b) {
    if(a<b) return b;
    else return a;  
}
ll MIN(ll a, ll b) {
    if(a>b) return b;
    else return a;
}
ll abs(ll a) {
    if(a>0) return a;
    else return -a;
}
void init_update(int pos, ll num) {
    it[pos].max = it[pos].min = it[pos].sum = num;
    int t = pos;
    while(t > 1) {
        t /= 2;
        it[t].max = MAX(it[2*t].max, it[2*t+1].max);
        it[t].min = MIN(it[2*t].min, it[2*t+1].min);
        it[t].sum = it[2*t].sum + it[2*t+1].sum;
    }
    return;
}
void push_down(int node, int mi, int st)
{
    if(it[node].color != -1) {
        it[node*2].color_sum += it[node].update_color_sum/2;
        it[node*2].color_sum += abs(it[node].color*(mi-st+1)-it[node*2].sum);
        it[node*2].max = it[node*2].min = it[node].c_color;
        it[node*2+1].color_sum += it[node].update_color_sum/2;
        it[node*2+1].color_sum += abs(it[node].color*(mi-st+1)-it[node*2+1].sum);
        it[node*2+1].max = it[node*2+1].min = it[node].c_color;
        it[node*2].sum = it[node].c_color*(mi-st+1);
        it[node*2+1].sum = it[node].c_color*(mi-st+1);
        if(node*2 < MX) {
            if(it[node*2].color != -1) it[node*2].update_color_sum += (mi-st+1) * abs(it[node].color - it[node*2].c_color);
            it[node*2].c_color = it[node].c_color;
            if(it[node*2].color == -1) it[node*2].color = it[node].color;
            if(it[node*2+1].color != -1) it[node*2+1].update_color_sum += (mi-st+1) * abs(it[node*2+1].c_color - it[node].color);
            it[node*2+1].c_color = it[node].c_color;
            if(it[node*2+1].color == -1) it[node*2+1].color = it[node].color;
            it[node*2].update_color_sum += it[node].update_color_sum/2;
            it[node*2+1].update_color_sum += it[node].update_color_sum/2;
        }
        it[node].update_color_sum = 0;
        it[node].color = -1;
        it[node].c_color = 0;
    }
    return;
}
void update_color(int node, int st, int en, int l, int r, ll c) {
    int mi = (st+en)/2;
    if(st == en) {
        it[node].color_sum += abs(it[node].max - c);
        it[node].max = c;
        it[node].min = c;
        it[node].sum = c;
        return;
    }
    if(st == l && en == r) {
        if(it[node].max <= c || it[node].min >= c) {
            it[node].max = it[node].min = c;
            it[node].color_sum += abs(c*(en-st+1)-it[node].sum);
            it[node].sum = c*(en-st+1);
            if(it[node].color != -1) it[node].update_color_sum += abs(it[node].c_color-c)*(en-st+1);
            it[node].c_color = c;
            if(it[node].color == -1) it[node].color = c;
        }
        else {
            it[node].max = it[node].min = c;
            push_down(node, mi, st);
            update_color(node*2, st, mi, l, mi, c);
            update_color(node*2+1, mi+1, en, mi+1, r, c);
            it[node].color_sum = it[2*node].color_sum + it[2*node+1].color_sum;
            it[node].sum = c*(en-st+1);
        }
        return;
    }
    push_down(node, mi, st);
    if(mi >= r) update_color(node*2, st, mi, l, r, c);
    else if(mi+1 <= l) update_color(node*2+1, mi+1, en, l, r, c);
    else {
        update_color(node*2, st, mi, l, mi, c);
        update_color(node*2+1, mi+1, en, mi+1, r, c);
    }
    it[node].color_sum = it[2*node].color_sum + it[2*node+1].color_sum;
    it[node].max = MAX(it[2*node].max, it[2*node+1].max);
    it[node].min = MIN(it[2*node].min, it[2*node+1].min);
    it[node].sum = it[2*node].sum + it[2*node+1].sum;
    return;
}
ll get_sum(int node, int st, int en, int l, int r) {
    int mi = (st+en)/2;
    if(st == l && en == r) return it[node].color_sum;
    if(it[node].color != -1) push_down(node, mi, st);
    if(mi >= r) return get_sum(node*2, st, mi, l, r);
    if(mi+1 <= l) return get_sum(node*2+1, mi+1, en, l, r);
    return get_sum(node*2, st, mi, l, mi) + get_sum(node*2+1, mi+1, en, mi+1, r);
}
int main() {
    int N, M, i, chk, t1, t2;
    ll t3;
    scanf("%d %d", &N, &M);
    for(i = 1; i < MX*2; i++) {
        it[i].min = 123456789;
        it[i].color = -1;
    }
    for(i = 0; i < N; i++) init_update(MX+i, i+1);
    for(i = 1; i <= M; i++) {
        scanf("%d", &chk);
        if(chk == 1) {
            scanf("%d %d %lld", &t1, &t2, &t3);
            update_color(1, 1, MX, t1, t2, t3);
        }
        if(chk == 2) {
            scanf("%d %d", &t1, &t2);
            printf("%lld\n", get_sum(1, 1, MX, t1, t2));
        }
    }
    return 0;
}