#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int arr[12];
int tarr[12];

int main(){
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<10; i++){
            char c;
            scanf(" %c", &c);
            if(c=='1') arr[i] = 1;
            else if(c=='0') arr[i] = 0;
            else arr[i] = -1;
        }

        int ans = 10;
        for(int i=0; i<(1<<10); i++){
            for(int j=0; j<10; j++){
                if(arr[j] == -1) tarr[j] = (i>>j)&1;
                else tarr[j] = arr[j];
            }
            int A = 0, B = 0;
            int AL = 5, BL = 5;
            for(int j=0; j<10; j++){
                if(j%2==0){
                    AL--;
                    A += tarr[j];
                }
                else{
                    BL--;
                    B += tarr[j];
                }
                if(B+BL<A || A+AL<B){
                    ans = min(ans, j+1);
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
}