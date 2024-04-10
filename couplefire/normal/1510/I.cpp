#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<double> gen(0.0, 1.0);

int n, m;
char s[10005];
int wrong[1005];
const double val = 0.75;
double pw[10005];

int main(){
    scanf("%d %d", &n, &m);
    pw[0] = 1.0;
    for(int i = 1; i<10005; i++) pw[i] = pw[i-1]*val;
    for(int i = 0; i<m; i++){
        scanf("%s", s);
        int curmin = 1e9;
        for(int j = 0; j<n; j++) curmin = min(curmin, wrong[j]);
        double w[2] = {0, 0};
        for(int j = 0; j<n; j++) w[s[j]-'0'] += pw[wrong[j]-curmin];
        double res = gen(rng)*(w[0]+w[1]);
        if(res >= w[0]) printf("1\n");
        else printf("0\n");
        fflush(stdout);
        char c; scanf(" %c", &c);
        for(int j = 0; j<n; j++) if(s[j] != c) wrong[j]++;
    }
}