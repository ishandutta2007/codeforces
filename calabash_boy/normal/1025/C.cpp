//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = 1e5+100;
const int MOD = -1;
LL pow_mod(LL x,LL y){
    LL ret = 1;
    for (;y;y>>=1){if (y&1) ret = ret*x%MOD;x = x*x%MOD;}
    return ret;
}
char s[2*maxn];
bool a[maxn*2];
int main(){
    scanf("%s",s);
    int len = strlen(s);
    for (int i=0;i<len;i++){
        s[len+i] = s[i];
    }
    for (int i=1;i<2*len;i++){
        a[i] = s[i] != s[i-1];
    }
    int ans =0;
    for (int i=1;i<2*len;){
        int j = i;
        if (!a[i]){
            i++;
            continue;
        }
        while (j<2*len && a[j] ==1){
            j ++;
        }
        ans = max(ans,j-i);
        i = j;
    }
    cout<<min(ans+1,len)<<endl;
    return 0;
}