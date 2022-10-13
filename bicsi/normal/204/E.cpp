#include <bits/stdc++.h>

using namespace std;

#define DIM 500000
int Sort[DIM], Class[18][DIM], In[DIM], Len[DIM], Count[DIM], Left[DIM];
long long Sol[DIM];
pair<int, int> Aux[DIM];

char cuv[DIM], str[DIM];
int n, k;

void build_array() {
    for(int i=1; i<=n; i++) {
        Aux[i] = {str[i], 0};
        Sort[i] = i;
    }

    for(int i=0; (1<<i)<=n; i++) {
        sort(Sort+1, Sort+n+1, [](int a, int b) {return Aux[a] < Aux[b];});

        for(int j=1; j<=n; j++) Class[i][Sort[j]] = Class[i][Sort[j-1]] + (Aux[Sort[j]] != Aux[Sort[j-1]]);
        for(int j=1; j<=n; j++) Aux[j] = {Class[i][j], Class[i][j+(1<<i)]};
    }
}


int lcp(int a, int b) {
    int i, r = 0;
    a = Sort[a]; b = Sort[b];

    int lim = min(Len[a], Len[b]);

    for(i=0; (1<<i)<=lim; i++);
    for(i--; i>=0; i--) {
        if((1<<i) <= lim && Class[i][a] == Class[i][b]) {
            r += (1 << i);
            a += (1 << i);
            b += (1 << i);
            lim -= (1 << i);
        }
    }


    return r;
}

int RMQ[18][DIM], Log[DIM];


 void build_rmq() {
    for(int i=2; i<=n; i++) {
        RMQ[0][i] = lcp(i-1, i);
        Log[i] = Log[i/2] + 1;
    }

    for(int i=1; (1<<i)<=n; i++)
    for(int j=1; j <= n-(1<<i)+1; j++) {
        RMQ[i][j] = min(RMQ[i-1][j], RMQ[i-1][j+(1<<(i-1))]);
    }
}

int lcp2(int a, int b) {
    if(a == b) return Len[Sort[a]];

    if(a > b) swap(a, b);

    a++;
    int l = Log[b-a+1];

    return min(RMQ[l][a], RMQ[l][b-(1<<l)+1]);
}

void make_left() {
    int l, r;
    for(r=1; !In[Sort[r]]; r++);
    l = r;

    int total = 0;
    for(; r<=n; r++) {
        if(++Count[In[Sort[r]]] == 1) total++;

        while(total > k || Count[In[Sort[l]]] > 1) {

            if(--Count[In[Sort[l]]] == 0)
                total--;

            l++;
        }

        if(total >= k) {
            Left[r] = l;
        } else {
            Left[r] = -1;
        }
    }
}

int M;
bool good(int i, int lc) {
    int step, l=i, r=i;
    for(step=M; step; step>>=1) {
        if(l-step>0  && lcp2(i, l-step) >= lc) l -= step;
        if(r+step<=n && lcp2(i, r+step) >= lc) r += step;
    }

    return Left[r] >= l;
}

void solve() {

    for(M=1; M<=n; M<<=1); M>>=1;

    for(int i=1; i<=n; i++) {
        int step, l = 0;

        for(step=1; step<=Len[Sort[i]]; step<<=1);
        for(step>>=1; step; step>>=1) {
            if(l + step <= Len[Sort[i]] && good(i, l + step))
                l += step;
        }

        Sol[In[Sort[i]]] += l;
    }
}

int main() {
    int cnt;
    cin>>cnt>>k;

    for(int i=1; i<=cnt; i++) {
        cin>>cuv;
        strcat(str + n + 1, cuv);
        n += strlen(cuv) + 1;

        for(int ii=n-1; str[ii]; ii--) {
            In[ii] = i;
            Len[ii] = n-ii;
        }
    }

    build_array();
    build_rmq();
    make_left();
    solve();

    for(int i=1; i<=cnt; i++) {
        cout<<Sol[i]<<' ';
    }


    return 0;
}