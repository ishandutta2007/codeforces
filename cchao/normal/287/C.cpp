#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, arr[100010];

int main(){
    cin >> n;
    if(n==1){puts("1");}
    else if(n%4 > 1){puts("-1");}
    else{
        memset(arr, -1, sizeof arr);
        for(int i = 0; i<n/2; i+=2){
            arr[i] = i+2;
            int now = i+1, last = i;
            while(arr[now] == -1){
                arr[now] = n-last;
                last = now;
                now = arr[now] - 1;
            }
        }
        if(n%4) arr[n/2] = n/2+1;
        for(int i = 0; i < n; ++i)
            printf("%d ", arr[i]);
        puts("");
    }
    return 0;
}