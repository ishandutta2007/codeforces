#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
using namespace std;
char s[200005];
int pre[200005][3];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) pre[i][j]=pre[max(i-3,0)][j];
            pre[i][s[i]-'a']++;
            //for(int j=0;j<3;j++) cout<<pre[i][j]<<" ";puts("");
        }
        for(int i=1,l,r;i<=q;i++){
            scanf("%d%d",&l,&r);
            if(l==r) puts("0");
            else if(r-l==1){
                if(s[l]==s[r]) puts("1");
                else puts("0");
            }
            else {
                int cost = n;
                for(int x=0;x<3;x++)
                    for(int y=0;y<3;y++)
                        for(int z=0;z<3;z++){
                            if(x==y||y==z||z==x) continue;
                            int tot=r-l+1,pos;
                            tot-=pre[r][x];
                            pos=l-1;
                            while(pos%3!=r%3&&pos) pos--;
                            tot+=pre[pos][x];
                            tot-=pre[r-1][y];
                            pos=l-1;
                            while(pos%3!=(r-1)%3&&pos) pos--;
                            tot+=pre[pos][y];
                            tot-=pre[r-2][z];
                            pos=l-1;
                            while(pos%3!=(r-2)%3&&pos) pos--;
                            tot+=pre[pos][z];
                            cost=min(cost,tot);
                            //cout<<x<<" "<<y<<" "<<z<<" "<<r-l+1-(pre[r][x]-pre[l-1][x]+pre[r-1][y]-pre[l-1][y]+pre[r-2][z]-pre[l-1][z])<<endl;
                        }
                printf("%d\n",cost);
            }
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!