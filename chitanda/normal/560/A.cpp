#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a, ak = 0;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a);
        if (a == 1) ak = 1;
    }
    if (ak) printf("-1\n");
    else printf("1\n");
    return 0;
}