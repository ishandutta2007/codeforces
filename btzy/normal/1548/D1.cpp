#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=6000;
int arr[4][4];
int do_gcd(int a, int b){
    if(b==0)return a;
    return do_gcd(b,a%b);
}
int ediff(int a, int b){
    int ret=(a-b)&3;
    if(ret==0)ret=4;
    return ret;
}
int bound(int i, int j){
    return do_gcd(i,j)&3;
}
int solve(int i, int j, int ii, int jj, int iii, int jjj){
    int d12i=ediff(i,ii);
    int d12j=ediff(j,jj);
    int d23i=ediff(ii,iii);
    int d23j=ediff(jj,jjj);
    int d31i=ediff(iii,i);
    int d31j=ediff(jjj,j);
    int b=(bound(d12i,d12j)+bound(d23i,d23j)+bound(d31i,d31j))&3;
    if(b&1)return 0;
    int area2=((ii-i)*(jj+j)+(iii-ii)*(jjj+jj)+(i-iii)*(j+jjj))&3;
    assert((area2&1)==0);
    if((b&2)^(area2&2))return 0;
    //if(arr[i][j]*arr[ii][jj]*arr[iii][jjj]!=0)cout<<i<<' '<<j<<' '<<ii<<' '<<jj<<' '<<iii<<' '<<jjj<<' '<<arr[i][j]*arr[ii][jj]*arr[iii][jjj]<<endl;
    return arr[i][j]*arr[ii][jj]*arr[iii][jjj];
}
int solve2(int i, int j, int ii, int jj){
    int iii=i;
    int jjj=j;
    int d12i=ediff(i,ii);
    int d12j=ediff(j,jj);
    int d23i=ediff(ii,iii);
    int d23j=ediff(jj,jjj);
    int d31i=ediff(iii,i);
    int d31j=ediff(jjj,j);
    int b=(bound(d12i,d12j)+bound(d23i,d23j)+bound(d31i,d31j))&3;
    if(b&1)return 0;
    int area2=((ii-i)*(jj+j)+(iii-ii)*(jjj+jj)+(i-iii)*(j+jjj))&3;
    assert((area2&1)==0);
    if((b&2)^(area2&2))return 0;
    //if(arr[i][j]*arr[ii][jj]!=0)cout<<i<<' '<<j<<' '<<ii<<' '<<jj<<' '<<arr[i][j]*arr[ii][jj]<<endl;
    return arr[i][j]*arr[ii][jj];
}
int solve3(int i, int j){
    int ii=i;
    int jj=j;
    int iii=i;
    int jjj=j;
    int d12i=ediff(i,ii);
    int d12j=ediff(j,jj);
    int d23i=ediff(ii,iii);
    int d23j=ediff(jj,jjj);
    int d31i=ediff(iii,i);
    int d31j=ediff(jjj,j);
    int b=(bound(d12i,d12j)+bound(d23i,d23j)+bound(d31i,d31j))&3;
    if(b&1)return 0;
    int area2=((ii-i)*(jj+j)+(iii-ii)*(jjj+jj)+(i-iii)*(j+jjj))&3;
    assert((area2&1)==0);
    if((b&2)^(area2&2))return 0;
    //if(arr[i][j]!=0)cout<<i<<' '<<j<<' '<<arr[i][j]<<endl;
    return arr[i][j];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        arr[x&3][y&3]++;
    }
    int ans=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            for(int ii=0;ii<4;++ii){
                for(int jj=0;jj<4;++jj){
                    for(int iii=0;iii<4;++iii){
                        for(int jjj=0;jjj<4;++jjj){
                            ans+=solve(i,j,ii,jj,iii,jjj);
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            for(int ii=0;ii<4;++ii){
                for(int jj=0;jj<4;++jj){
                    ans-=3*solve2(i,j,ii,jj);
                }
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            ans+=2*solve3(i,j);
        }
    }
    cout<<ans/6<<'\n';
}