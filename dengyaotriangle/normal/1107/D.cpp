#include<bits/stdc++.h>

using namespace std;

const int maxn=5204;

int n;
int v[maxn][maxn];

int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j+=4){
            int f=getchar();
            if(isdigit(f))f-='0';
            else f-=(int)'A'-10;
            v[i][j]=(f&8)>>3;
            v[i][j+1]=(f&4)>>2;
            v[i][j+2]=(f&2)>>1;
            v[i][j+3]=f&1;
        }
        getchar();
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    vector<int> vc;
    int g=n;
    for(int i=1;i*i<=n;i++){
        if(g%i==0){
            vc.push_back(i);
            if(i*i!=n){
                vc.push_back(n/i);
            }
        }
    }
    //if(g!=1) vc.push_back(g);
    sort(vc.begin(),vc.end());
    for(int i=vc.size()-1;i>=1;i--){
        bool ok=1;
        for(int j=vc[i];j<=n;j+=vc[i]){
            for(int k=vc[i];k<=n;k+=vc[i]){
                int q=v[j][k]-v[j-vc[i]][k]-v[j][k-vc[i]]+v[j-vc[i]][k-vc[i]];
                if(q!=0&&q!=vc[i]*vc[i]){
                    ok=0;
                    break;
                }
            }
            if(ok==0) break;
        }
        if(ok){
            cout<<vc[i];
            return 0;
        }
    }
    cout<<1;
    return 0;
}