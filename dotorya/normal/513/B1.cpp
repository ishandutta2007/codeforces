#include <stdio.h>
typedef long long ll;
int chk[100050];
int main() {
    int N;
    ll M;
    scanf("%d %lld", &N, &M);
    ll st = (1ll<<N)-M;
    for(int i = N-1; i >= 0; i--) {
        if(st % 2 == 1) chk[i]++;
        st /= 2;
    }
    
    for(int i = 1; i <= N; i++) if(chk[i] == 1) printf("%d ", i);
    for(int i = N; i >= 1; i--) if(chk[i] == 0) printf("%d ", i);
    return 0;
}