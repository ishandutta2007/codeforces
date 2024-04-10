#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006

int n;
long long psum[MAXN];
pair<long long, int> st[MAXN];
int top = 0;

int main(){
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) scanf("%d", &psum[i]), psum[i] += psum[i-1];
    for(int i = 0; i<=n; i++){
        while(top > 1 && (psum[i]-st[top-1].first)*(st[top-1].second-st[top-2].second) <= (st[top-1].first-st[top-2].first)*(i-st[top-1].second)) top--;
        st[top++] = {psum[i], i};
    }
    for(int i = 0; i<top-1; i++) for(int j = 0; j<st[i+1].second-st[i].second; j++) printf("%.9f\n",(0.0+st[i+1].first-st[i].first)/(st[i+1].second-st[i].second));
}