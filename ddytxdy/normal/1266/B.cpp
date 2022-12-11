#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t;LL n;
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>n;
        if(n<15){puts("NO");continue;}
        bool flag=0;
        for(int i=1;i<=6;i++)if((n-i)%14==0)flag=1;
        puts(flag?"YES":"NO");
    }
    return 0;
}