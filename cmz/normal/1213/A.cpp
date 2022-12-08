#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],n,cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]%2)
            cnt++;
    cout<<min(cnt,n-cnt)<<endl;
    return 0;
}