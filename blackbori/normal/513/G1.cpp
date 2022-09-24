#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int N,K;
int C[10];
double ans=0 ,c=0;

int sw(int s,int e)
{
    int i,t;
    for(i=s; i<=(s+e)/2; i++){
        t = C[i];
        C[i] = C[(s+e)-i];
        C[(s+e)-i] = t;
    }
    return 0;
}

int inv(int s,int e)
{
    if(C[s] > C[e]) return true;
    else return false;
}

int F(int b)
{
    int i,j;
    if(b == 0){
        for(i=1; i<=N; i++){
            for(j=i; j<=N; j++){
                if(inv(i,j)) ans++;
            }
        }
        c++;
        return 0;
    }
    for(i=1; i<=N; i++){
        for(j=i; j<=N; j++){
            sw(i,j);
            F(b-1);
            sw(i,j);
        }
    }
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d",&N,&K);
    int i;
    for(i=1; i<=N; i++) scanf("%d",&C[i]);

    F(K);

    printf("%.15lf",ans/c);

    return 0;
}