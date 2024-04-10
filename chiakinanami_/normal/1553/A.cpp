#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

int main(){
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d", &n);
        printf("%d\n", (n+1)/10);
    }
}