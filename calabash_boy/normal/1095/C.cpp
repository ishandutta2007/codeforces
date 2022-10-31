#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int num[50];

int n,k;
int get_sum(int top){
    int sum = 0;
    for (int i=0;i<=top;i++){
        sum += num[i] * (1<< i);
    }
    return sum;
}
int main(){
    cin>>n>>k;
//    int sum = 0;
    for (int i=0;i<32;i++){
        int mask = 1 << i;
        if (n & mask){
            num[i] = 1;
        }else{
            num[i] = 0;
        }
    }
    if (k > n){
        puts("NO");
        return 0;
    }
    if(k < __builtin_popcount(n)){
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=31;i>=0;i--){
        if (num[i] == 0)continue;
        int sum = get_sum(i-1);
        while(num[i] && sum + num[i] <k){
            num[i] --;
            num[i-1] += 2;
            sum += 1<<i;
        }
        k -= num[i];
    }
    for(int i=0;i<31;i++){
        for (int j=0;j<num[i];j++){
            printf("%d ",1<<i);
        }
    }
    puts("");
    return 0;
}