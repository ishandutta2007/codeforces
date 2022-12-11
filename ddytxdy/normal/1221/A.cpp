#include<bits/stdc++.h>
using namespace std;
const int N=50;
int q,n,a[N];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);memset(a,0,sizeof(a));
        for(int i=1,x;i<=n;i++)scanf("%d",&x),a[(int)log2(x)]++;
        // for(int i=1;i<=30;i++)printf("%d ",a[i]);puts("");
        for(int i=0;i<=10;i++)a[i+1]+=a[i]>>1;
        puts(a[11]?"yes":"no");
    }
    return 0;
}