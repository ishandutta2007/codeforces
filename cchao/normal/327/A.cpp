#include <cstdio>
#include <iostream>
using namespace std;
int arr[110];
int main() {
    int n, one = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] == 1) one++;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j) {
            int a = 0, b = 0;
            for(int k = i; k <= j; ++k)
                if(arr[k] == 1) a++;
                else b++;
            ans = max(ans, one + b - a); 
        }
    printf("%d\n", ans);
    return 0;
}