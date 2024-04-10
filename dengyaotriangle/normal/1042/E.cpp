#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=1005;
const long long mdn=998244353;

struct poi{
    int x,y,v;
};
long long gs[6];

long long ksm(long long bse,long long ex){
    if(!ex)return 1;
    long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
    if(ex&1)ans=(ans*bse)%mdn;
    return ans;
}
int n,m;
vector<poi> vec;
long long ans[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            poi c;c.x=i;c.y=j;cin>>c.v;
            vec.push_back(c);
        }
    }
    sort(vec.begin(),vec.end(),[](poi a,poi b){
        return a.v<b.v;
    });
    int tx,ty;cin>>tx>>ty;
    int cp=0;
    long long hsm=0;
    for(int i=0;i<vec.size();i++){
        int cx=vec[i].x,cy=vec[i].y,cv=vec[i].v;
        while(vec[cp].v<cv){
            int gx=vec[cp].x,gy=vec[cp].y;
            gs[0]=(gs[0]+(gx*gx))%mdn;
            gs[1]=(gs[1]+(gx))%mdn;
            gs[2]=(gs[2]+(gy*gy))%mdn;
            gs[3]=(gs[3]+(gy))%mdn;
            gs[4]=(gs[4]+(1))%mdn;
            hsm+=ans[gx][gy];
            cp++;
        }
        long long qx=(gs[0]+gs[4]*cx*cx-gs[1]*cx*2)%mdn;
        long long qy=(gs[2]+gs[4]*cy*cy-gs[3]*cy*2)%mdn;
        ans[cx][cy]=(qx+qy+hsm+mdn+mdn)%mdn;
        ans[cx][cy]=(ans[cx][cy]*ksm(cp,mdn-2))%mdn;
        if(cx==tx&&cy==ty){
            cout<<ans[cx][cy];
            return 0;
        }
    }
    return 0;
}