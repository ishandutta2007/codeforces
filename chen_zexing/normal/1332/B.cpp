#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
int a[1005],f[1005],cnt[15],num[15]={0,2,3,5,7,11,13,17,19,23,29,31};
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=11;i++){
            for(int j=1;j<=n;j++)
                if(a[j]%num[i]==0&&f[j]==0){
                    cnt[i]++;
                    f[j]=1;
                }
        }
        int ans=0;
        for(int i=1;i<=11;i++)
            if(cnt[i])
                ans++;
        printf("%d\n",ans);
        memset(f,0,sizeof(f));
        int x=1;
        for(int i=1;i<=11;x+=(cnt[i]>0),i++)
            for(int j=1;j<=n;j++){
                if(a[j]%num[i]==0&!f[j]){
                    f[j]=x;
                }
            }
        for(int j=1;j<=n;j++) printf("%d ",f[j]);
        printf("\n");
    }
    return 0;
}