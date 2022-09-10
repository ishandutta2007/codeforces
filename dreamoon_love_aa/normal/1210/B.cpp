#include<bits/stdc++.h>
long long a[7000], b[7000];
bool choosen[7000];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    long long an = 0;
    for(int i = 0; i < n; i++) {
        bool good = false;
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                good = true;
                break;
            }
        }
        if(good) {
            for(int j = 0; j < n; j++) {
                if((a[i] & a[j]) == a[j]) choosen[j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(choosen[i]) an += b[i];
    }
    printf("%lld\n", an);
    return 0;
}