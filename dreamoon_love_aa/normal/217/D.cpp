#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
#include<bitset>
#define MOD 1000000007
using namespace std;
int d[120],m,now,half;
long long used,used2,an;
inline int to(int x){
    if(x<0)return x+m;
    if(x>=m)return x-m;
    return x;
}
inline int to2(int x){
    return min(x,m-x);
}
void dfs(int x,int y,long long v,bitset<120>& used){
    if(x>y)return;
    dfs(x+1,y,v,used);
    if(!d[x]||used[x])return;
    bitset<120>last_used=used;
    used|=last_used<<x;
    used|=last_used>>x;
    used|=last_used<<(m-x);
    used|=last_used>>(m-x);
    used.set(x);
    used.set(m-x);
    an+=v*d[x]%MOD;
    dfs(x+1,y,v*d[x]%MOD,used);
    used=last_used;
}
int main(){
    int i,j,k,n,t;
    an=1;
    scanf("%d%d%d",&n,&m,&t);
    half=m/2;
    while(t--){
        int x;
        scanf("%d",&x);
        d[to2(x%m)]++;
    }
    if(m==1){
        puts("1");
        return 0;
    }
    if(m==2||m==3){
        cout<<d[1]<<endl;
        return 0;
    }
    bitset<120>used;
    dfs(1,m/2,1,used);
    an%=MOD;
    cout<<an<<endl;
    return 0;
}