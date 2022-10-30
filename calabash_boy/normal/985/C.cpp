#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+200;
int a[maxn];
int n,k,l;
int b[maxn],tot;
int main(){
    scanf("%d%d%d",&n,&k,&l);
    int N = n*k;
    for (int i=0;i<N;i++){
        scanf("%d",a+i);
    }
    sort(a,a+N);
    if(a[n-1]-a[0]>l){
        cout<<0<<endl;
        return 0;
    }
    for (int i=0;i<N;i++){
        if(a[i]<=a[0]+l){
            b[tot++] = a[i];
        }else{
            break;
        }
    }
    long long ans =0;
    int j=0;
    for (int i=n;i>=1;i--){
        ans+=b[j];
        j = min(j+k,tot-i+1);
    }
    cout<<ans<<endl;
    return 0;
}