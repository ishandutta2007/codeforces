#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
const int HASH_NUM = 3;
typedef long long LL;
int AC[HASH_NUM] ={131,137,139};
int ACC[HASH_NUM] ={200003,200009,200017};
LL bas[maxn][HASH_NUM];
int n;
char s[maxn];
LL sum1[maxn][HASH_NUM];
int ans[maxn];
bool check(int index,int x,int len){
    LL hs1 = ((sum1[x+len-1][index]-sum1[x-1][index]*bas[len][index]%ACC[index])%ACC[index]+ACC[index])%ACC[index];
    LL hs2 = ((sum1[n-x+1][index]-sum1[n-x-len+1][index]*bas[len][index]%ACC[index])%ACC[index]+ACC[index])%ACC[index];
    if (hs1==hs2)return true;
    else return false;
}
bool check(int x,int len){
    for (int i=0;i<HASH_NUM;i++){
        if (!check(i,x,len))return false;
    }
    return true;
}

int calc(int x){
    for (int len = n-2*(x-1)-1;len;len--){
        if (len%2&&check(x,len)){
            return len;
        }
    }
    return -1;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int o =0;o<HASH_NUM;o++){
        bas[0][o]=1;
        for (int i=1;i<=n;i++){
            bas[i][o] = bas[i-1][o]*AC[o]%ACC[o];
        }
        for (int i=1;i<=n;i++){
            sum1[i][o] = (sum1[i-1][o]*AC[o]%ACC[o]+s[i]-'a'+1)%ACC[o];
        }
    }
    int topi = (n+1)>>1;
    for (int i=topi;i>=1;i--){
        if (i==topi){
            if (n%2==1)
            {
                ans[i]=-1;
            }
            else
            {
                if (s[i]==s[i+1])
                {
                    ans[i]=1;
                }
                else
                {
                    ans[i]=-1;
                }
            }
        }else{
            ans[i] = ans[i+1]+2;
            while (ans[i]!=-1&&check(i,ans[i])==false){
                ans[i]-=2;
            }
        }
    }
    for (int i=1;i<=topi;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}