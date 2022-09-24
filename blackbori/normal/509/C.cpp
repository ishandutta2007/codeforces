#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

int max(int a,int b) { return a>b? a:b;}
int N,Len=0;
int D[343];
int E[343];
int String[343];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&N);

    int i,j,k,l;
    for(i=0; i<N; i++){
        scanf("%d",&D[i+1]);
    }
    D[0] = 0;
    for(i=0; i<301; i++) String[i] = 0;

    for(i=0; i<N; i++){
        k = D[i+1] - D[i];
        if(k > 0){
            j=0;
            while(k>0){
                Len = max(Len,j);
                //printf("%d %d %d\n",i,j,k);
                if(k<(9-String[j])){
                    String[j] += k;
                    k=0;
                }
                else{
                    k -= (9-String[j]);
                    String[j] = 9;
                }
                j++;
            }
        }
        else{
            E[Len+1] = 0;
            for(j=Len; j>=0; j--) E[j] = E[j+1] + String[j];
            for(j=0; j<=Len+1; j++){
                Len = max(Len,j);
                if(String[j] == 9) continue;
                String[j] ++;
                for(k=0; k<j; k++){
                    String[k] = 0;
                }
                l=0; k=D[i+1]-E[j+1]-String[j];
                if(k < 0) continue;
                while(k>0){
                    if(l>j) break;
                    if(k<9){
                        String[l] = k;
                        break;
                    }
                    k-=9;
                    String[l] = 9;
                    l++;
                }
                if(l<=j) break;
            }
        }
        for(j=Len; j>=0; j--){
            printf("%d",String[j]);
        }
        printf("\n");
    }

    return 0;
}