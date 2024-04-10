#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
bool isp[3505],cp[3505][3505];
pair<int,int> rg[3505];
int main(){
    int l,r,n;
    cin>>n>>l>>r;
    if(n==1)cout<<r-l+1<<endl;
    else if(n==2)cout<<(long long)(r-l+1)*(r-l)<<endl;
    else{
        long long ans=0LL;
        int maxb=(int)(pow((double)(r),1.0/(n-1))+1e-9);
        for(int rat=1;rat<=maxb;rat++){
            int cur=(int)(pow((double)(rat),n-1));
            rg[rat]=make_pair((l-1)/cur+1,r/cur);
        }
        for(int i=2;i<=maxb;i++)isp[i]=true;
        for(int i=2;i<=maxb;i++)if(isp[i])
            for(int j=i+i;j<=maxb;j+=i)
                isp[j]=false;
        for(int i=1;i<=maxb;i++)for(int j=i;j<=maxb;j++)
            cp[i][j]=true;
        cp[1][1]=false;
        for(int i=2;i<=maxb;i++)if(isp[i])
            for(int j=i;j<=maxb;j+=i)
                for(int k=j;k<=maxb;k+=i)
                    cp[j][k]=false;
        for(int i=1;i<=maxb;i++)for(int j=i;j<=maxb;j++)
            if(cp[i][j]){
                int l=max(rg[i].first,rg[j].first),r=min(rg[i].second,rg[j].second);
                ans+=max(r+r-l-l+2,0);
            }
        cout<<ans<<endl;
    }
    return 0;
}