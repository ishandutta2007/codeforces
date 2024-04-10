#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],pre[200005];
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+(i%2?a[i]:-a[i]);
        if((pre[n]%2+2)%2){
            puts("-1");
            continue;
        }
        if(!pre[n]){
            printf("1\n1 %d\n",n);
            continue;
        }
        int f=0;
        for(int i=1;i<n;i++){
            if(pre[i]*2==pre[n]&&i%2){
                printf("2\n1 %d\n%d %d\n",i,i+1,n);
                f=1;
                break;
            }
        }
        if(!f){
            for(int i=1;i<n;i++)
                if(pre[i]*2==pre[n]&&a[i]+a[i+1]==0){
                    vector <pair<int,int>> v;
                    if(i>1) v.push_back({1,i-1});
                    v.push_back({i,i});
                    v.push_back({i+1,i+1});
                    if(i<n-1) v.push_back({i+2,n});
                    printf("%d\n",int(v.size()));
                    for(auto t:v) printf("%d %d\n",t.first,t.second);
                    f=1;
                    break;
                }
            assert(f);
        }
    }
    return 0;
}