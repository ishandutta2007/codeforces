#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>

using namespace std;

#define ull unsigned long long
#define MAX 100025

ull ss[MAX];

int main() {
#if DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);

    char s[MAX];

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++){
            scanf("%s", s);
            for(int j=0; j<m; j++){
                ss[j]+=s[j];
            }
        }

        for(int i=0; i<n-1; i++){
            scanf("%s", s);
            for(int j=0; j<m; j++){
                ss[j]-=s[j];
            }
        }

        for(int j=0; j<m; j++){
            s[j]=ss[j];
            ss[j]=0;
        }


        printf("%s\n", s);
    }

    return 0;
}