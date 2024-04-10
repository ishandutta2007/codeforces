#include <bits/stdc++.h>
#define left asdklfjasd
#define right ekjljlkd
using namespace std;
const int maxn = 200000 + 50;
int n,q;
int a[maxn];
int rightest[maxn];
int left[maxn];
int right[maxn];
bool used[maxn];
int ans = 0;
void gao(int l,int r){
    map<int,int> cnt;
    int max_cnt = 0;
    for (int i=l;i<=r;i++){
        used[i] = 1;
        cnt[a[i]] ++;
        max_cnt = max(max_cnt,cnt[a[i]]);
    }
    ans += r - l + 1 - max_cnt;
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<maxn;i++){
        left[i] = -1;
        right[i] = -1;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        if (left[a[i]] == -1){
            left[a[i]] = i;
            right[a[i]] = i;
        }else{
            left[a[i]] = min(left[a[i]],i);
            right[a[i]] = max(right[a[i]],i);
        }
    }
    for (int i=1;i<maxn;i++){
        if (left[i] != -1){
            rightest[left[i]] = max(rightest[left[i]],right[i]);
        }
    }
 
    for (int i=1;i<=n;i++){
        if (used[i])continue;
        assert(rightest[i]);
        int nowl = i;
        int nowr = rightest[i];
        for (int j = nowl;j <= nowr;j ++){
            nowr = max(nowr,rightest[j]);
        }
        gao(nowl,nowr);
    }
    cout<<ans<<endl;
    return 0;
}