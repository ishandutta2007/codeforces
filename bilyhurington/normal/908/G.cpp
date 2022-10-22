/*
 * @Author: BilyHurington
 * @Date: 2021-07-01 11:24:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-07-01 11:51:09
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,f[710][710][10][2];
char s[710];
const int mod=1e9+7;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int del(int x,int y){return x>=y?x-y:x+mod-y;}
inline void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void Del(int &x,int y){x-=y;if(x<0) x+=mod;}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=0;i<10;i++) f[0][0][i][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<10;k++){
                for(int t=0;t<10;t++){
                    for(int r=0;r<2;r++){
                        if(!r&&t>s[i+1]-'0') continue;
                        Add(f[i+1][j+(t>=k)][k][r|(t<(s[i+1]-'0'))],f[i][j][k][r]);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<10;i++){
        for(int j=1,t=1;j<=n;j++){
            Add(ans,1ll*t*f[n][j][i][0]%mod);
            Add(ans,1ll*t*f[n][j][i][1]%mod);
            t=(10ll*t+1)%mod;
        }
    }
    printf("%d",ans);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}