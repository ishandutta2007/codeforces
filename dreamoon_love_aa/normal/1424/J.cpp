#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
bool notprime[1000010];
int sumprime[1000010];
void fun(){
    for(int i = 2; i <= 1000000; i++){
        if(notprime[i] == 0){
            for(int j = i*2; j <= 1000000;j+=i){
                notprime[j] = 1;
            }
         }
    }
}
void sum(){
    sumprime[1] = 0;
    for(int i = 2; i <= 1000000;i++){
        sumprime[i] = sumprime[i-1]+(!notprime[i]);
    }
}
int main() {
    int n,x;
    scanf("%d",&n);
    fun();
    sum();
    while(n--){
        scanf("%d",&x);
        int sum = sumprime[x]-sumprime[(int)sqrt(x)]+1;
        printf("%d\n",sum);
    }
    return 0;
}