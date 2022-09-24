#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

int m,t,r;
int Ghost[330][2];
bool Candle[660],ff=0;
int ans=0;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d %d",&m,&t,&r);

    int i,j,l;
    for(i=0; i<m; i++){
        scanf("%d",&Ghost[i][0]);
        Ghost[i][0] += 301;
        Ghost[i][1] = r;
    }

    for(i=0; i<m; i++){
        for(j=Ghost[i][0]; j>Ghost[i][0]-t; j--){
            if(Ghost[i][1]<=0) break;
            if(Candle[j]) continue;
            Candle[j] = true;
            ans++;
            for(l=i; l<m; l++){
                if(Ghost[l][0] >= j+t) break;
                Ghost[l][1]--;
            }
        }
        if(Ghost[i][1]!=0){
            ff=1; break;
        }
    }

    if(ff) printf("-1\n");
    else printf("%d\n",ans);

    return 0;
}