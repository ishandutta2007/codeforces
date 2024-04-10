#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n,a[N],k;

void solve(){

}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n==1){
            if(a[1]==k) puts("yes");
            else puts("no");
            continue;
        }
        int flag=0;
        for(int i=1;i<=n;i++) if(a[i]==k) flag=1;
        if(!flag){
            puts("no");
            continue;
        }
        flag=0;
        int now=(a[1]>=k ? 1 : -1);
        for(int i=2;i<=n;i++){
            int tmp=(a[i]>=k ? 1 : -1);
            if(now+tmp>0) flag=1;
            if(now<0) now=tmp;
            else now=now+tmp;
        }
        if(flag) puts("yes");
        else puts("no");
    }
}