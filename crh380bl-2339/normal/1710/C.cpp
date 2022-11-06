#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
char s[200005];
long long f[200005][2][2][2][2][2][2];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    int id,i,j,k,l,x,y,ii,jj,kk,z;
    int iii,jjj,kkk,aaa,bbb;
    for(i=1;i<=n;++i)s[i]-='0';
    f[0][1][1][1][1][1][0]=1;
    for(id=1;id<=n;++id){
        for(i=0;i<=1;++i)for(j=0;j<=1;++j)for(k=0;k<=1;++k)for(x=0;x<=1;++x)for(y=0;y<=1;++y)for(z=0;z<=1;++z){
            for(ii=0;ii<=1;++ii)for(jj=0;jj<=1;++jj)for(kk=0;kk<=1;++kk){
                if(i&&ii>s[id])continue;
                else{
                    iii = i&(ii==s[id]);
                }
                if(j&&jj>s[id])continue;
                else{
                    jjj = j&(jj==s[id]);
                }
                if(k&&kk>s[id])continue;
                else{
                    kkk = k&(kk==s[id]);
                }
                int aa=ii^jj,bb=ii^kk,cc=jj^kk;
                if(x&&aa>cc)continue;
                else{
                    aaa = x&(aa==cc);
                }
                if(y&&bb>cc)continue;
                else{
                    bbb = y&(bb==cc);
                }
                int zzz = z||(aa+bb>cc);
                //printf("(%d,%d,%d,%d,%d)-->(%d,%d,%d)-->(%d,%d,%d,%d,%d)\n",i,j,k,x,y,ii,jj,kk,iii,jjj,kkk,aaa,bbb);
                (f[id][iii][jjj][kkk][aaa][bbb][zzz] += f[id-1][i][j][k][x][y][z])%=mod;
            }
        }
    }
    long long ans=0;
    for(i=0;i<=1;++i)for(j=0;j<=1;++j)for(k=0;k<=1;++k)(ans+=f[n][i][j][k][0][0][1])%=mod;
    ans=ans*3%mod;
    printf("%lld\n",ans);
    return 0;
}