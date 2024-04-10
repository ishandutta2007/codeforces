/*
 * @Author: BilyHurington
 * @Date: 2021-07-13 12:15:34
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-13 15:09:02
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,A[1010][510],C[510][510];
bool tag[1010];
void solve(){
    vector<int> pos;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) C[i][j]=0;
    }
    for(int i=1;i<=2*n;i++) tag[i]=0;
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&A[i][j]);
            C[j][A[i][j]]++;
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        int D=0;
        for(int j=1;j<=2*n;j++){
            if(tag[j]) continue;
            for(int k=1;k<=n;k++){
                if(C[k][A[j][k]]==1){
                    D=j;break;
                }
            }
            if(D) break;
        }
        if(!D){
            ans=ans*2%998244353;
            for(D=1;tag[D];D++);
        }
        pos.push_back(D);
        for(int j=1;j<=2*n;j++){
            if(tag[j]) continue;
            bool pd=0;
            for(int k=1;k<=n;k++){
                if(A[D][k]==A[j][k]){
                    pd=1;break;
                }
            }
            if(!pd) continue;
            tag[j]=1;
            for(int k=1;k<=n;k++) C[k][A[j][k]]--;
        }
    }
    printf("%d\n",ans);
    for(auto x:pos) printf("%d ",x);puts("");
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}