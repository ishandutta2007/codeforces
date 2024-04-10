#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;
int n,m;
void solve(){
    scanf("%d %d",&n,&m);
    if(m<n){puts("No");return;}
    if(n%2==0){
        if(m%2==0){puts("Yes");
            for(int i=1;i<=n-2;i++) printf("1 ");
            m-=n-2;
            printf("%d %d\n",m/2,m/2);
        }else{puts("No");return;}
    }else{
        puts("Yes");
        for(int i=1;i<=n;i++){
            if(i<n) printf("1 ");
            else printf("%d\n",m-(n-1));
        }
    }
}
int main(){int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}