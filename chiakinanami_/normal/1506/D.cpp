#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n;
int arr[200002];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
        sort(arr+1, arr+n+1);

        int maxOcc = 0;
        for(int i=1; i<=n; i++){
            int j = i;
            while(j<n && arr[i] == arr[j+1]) j++;
            maxOcc = max(maxOcc, j-i+1);
            i=j;
        }

        if(maxOcc * 2 <= n){
            printf("%d\n", n%2);
        }
        else{
            printf("%d\n", n - (n-maxOcc)*2);
        }
    }
}