#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        long long ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt[20]={},nxt[20]={};
        //123123412021,51362371238112912212111322
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans+=1LL*i*(n-i+1);
            }
            memset(nxt,0,sizeof(nxt));
            if(a[i]==0){
                memcpy(nxt,cnt,sizeof(cnt));
                nxt[11]++;
            }
            else if(a[i]==1){
                nxt[1]=cnt[1]+cnt[11]+cnt[3]+1;
                nxt[0]=cnt[2]+cnt[0];
                nxt[4]=cnt[4]+cnt[6];
                nxt[12]=cnt[5]+cnt[12];
                nxt[8]=cnt[7]+cnt[8];
                nxt[9]=cnt[9]+cnt[13];
            }
            else if(a[i]==2){
                nxt[2]=cnt[2]+cnt[11]+cnt[3]+1;
                nxt[0]=cnt[5]+cnt[0];
                nxt[4]=cnt[4]+cnt[1];
                nxt[13]=cnt[6]+cnt[13];
                nxt[9]=cnt[7]+cnt[9];
                nxt[8]=cnt[8]+cnt[12];
            }
            else{
                nxt[3]=cnt[1]+cnt[2]+cnt[3]+cnt[11]+1;
                nxt[6]=cnt[4]+cnt[6]+cnt[13];
                nxt[5]=cnt[5]+cnt[0]+cnt[12];
                nxt[7]=cnt[7]+cnt[8]+cnt[9];
            }
            swap(cnt,nxt);
            ans+=cnt[1]+cnt[2]+cnt[3]+(cnt[0]+cnt[4]+cnt[5]+cnt[6]+cnt[12]+cnt[13])*2+(cnt[7]+cnt[8]+cnt[9])*3;
            //for(int j=0;j<=11;j++) cout<<cnt[j]<<" ";puts("");
        }
        printf("%lld\n",ans);
    }
    return 0;
}