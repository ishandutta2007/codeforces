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
const int maxn = 1e5+10;
const int MOD = -1;
int a[maxn];
bool used[maxn];
int l[maxn];
int tot;
int cnt[maxn];
int n;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        if (l[a[i]]==0){
            l[a[i]]=i;
        }
    }
    for (int i=n;i>=1;i--){
        cnt[i] = tot;
        if (!used[a[i]]){
            used[a[i]]=1;
            tot++;
        }
    }
    LL ans =0;
    for (int i=1;i<=n;i++){
        if (i==l[a[i]]){
            ans += cnt[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}