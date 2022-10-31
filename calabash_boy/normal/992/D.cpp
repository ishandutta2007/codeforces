//
// Created by calabash_boy on 18-6-19.
//
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int MOD = 1e9+7;const int maxn =2e5+100;
typedef long double db;
LL a[maxn];
LL n,K;
LL sum=0;
int fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x] = find(fa[x]);
}
void spj(){
    for (int i=1;i<n;i++){
        if(a[i]==1&&a[i+1]==1){
            fa[find(i)] = find(i+1);
        }
    }
    LL ans =0;
    for (int i=1;i<=n;i++){
        LL tempSum =K*a[i];
        LL tempPro =a[i];
        int j=i;
        do{
            if(tempSum==tempPro)ans++;
            j++;
            if(j>n)break;
            if(find(j)==j){
                tempSum+=K*a[j];
                volatile LL PP = tempPro*a[j];
                if(PP<0||PP%a[j]!=0||PP/a[j]!=tempPro)break;
                tempPro*=a[j];
            }else{
                int k = find(j);
                LL l = tempSum+K;
                LL r = tempSum+1LL*K*(k-j+1);
                if(l<=tempPro&&tempPro<=r&&(tempPro-tempSum)%K==0){
                    int delta = (tempPro-tempSum)/K-1;
                    j +=delta;
                    tempSum=tempPro;
                }else{
                    tempSum+=K*(k-j+1);
                    j = find(j);

                }
            }

        }while (tempPro<=sum&&j<=n);
    }
    cout<<ans<<endl;
}

int main(){
    scanf("%I64d%I64d",&n,&K);
    for (int i=1;i<=n;i++){
        scanf("%I64d",a+i);
        fa[i]=i;
        sum+=a[i];
    }
    sum*=K;
    spj();
    return 0;
}