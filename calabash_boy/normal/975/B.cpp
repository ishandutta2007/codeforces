#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
int a[maxn];
int b[maxn];
long long calc(int st){
    long long tempAns =0;
    int roundGod = a[st]/14;
    for (int i=0;i<14;i++){
        b[i]=a[i];
    }
    b[st]=0;
    for (int i=0;i<14;i++){
        b[i]+=roundGod;
    }
    int rest = a[st]%14;
    for (int i=0;i<rest;i++){
        b[(st+1+i)%14]++;
    }
    for (int i=0;i<14;i++){
        if (b[i]%2==0){
            tempAns +=b[i];
        }
    }
    return tempAns;
}
int main(){
    for (int i=0;i<14;i++){
        scanf("%d",a+i);
    }
    long long ans =0;
    for (int i=0;i<14;i++){
        ans = max(ans,calc(i));
    }
    cout<<ans<<endl;
    return 0;
}