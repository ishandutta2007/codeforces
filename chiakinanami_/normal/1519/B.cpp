#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, m, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        printf("%s\n", k==n*m-1 ? "YES" : "NO");
    }
}