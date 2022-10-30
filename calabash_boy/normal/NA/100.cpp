#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int st[maxn],top;
int a[maxn],cnt[maxn];
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n-1;i++){
        scanf("%d",a+i);
    }
    for (int i=0;i<k;i++){
        cnt[i] = a[i];
    }
    for (int i=k;i<n-1;i++){
        st[top++] =i;
        while (top>0&&cnt[i-k]){
            int now = st[top-1];
            if (now<=i-k)break;
            int temp = min(cnt[i-k],a[now]-cnt[now]);
            cnt[now]+=temp;
            cnt[i-k]-=temp;
            if (cnt[now]==a[now])top--;
        }
    }
    int ans =0;
    for (int i=n-k-1;i<n-1;i++){
        ans+=cnt[i];
    }
    printf("%d\n",ans);
}