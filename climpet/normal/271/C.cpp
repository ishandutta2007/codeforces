#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    if(n < k * 3){
        puts("-1");
    }
    else{
        vector<int> a(n, 1);
        for(int i = 0; i < k; ++i){
            a[i*2] = a[i*2+1] = a[2*k+i] = i + 1;
        }
        printf("%d", a[0]);
        for(int i = 1; i < n; ++i){
            printf(" %d", a[i]);
        }
        puts("");
    }
}