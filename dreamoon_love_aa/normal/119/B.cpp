#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define SIZE 112
#define MAX 1e12
int a[SIZE];
vector<int>H;
double mi,ma;
bool used[SIZE];
int main(){
    int i,j,k,n,q,m;
    scanf("%d%d",&n,&k);
    mi=MAX;
    ma=-MAX;
    m=n/k;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        H.push_back(a[i]);
    }
    sort(H.begin(),H.end());
    scanf("%d",&q);
    int d[SIZE];
    while(q--){
        for(i=0;i<m;i++)scanf("%d",&d[i]);
        if(used[d[0]])continue;
        double tmp=0;
        for(i=0;i<m;i++){
            used[d[i]]=1;
            tmp+=a[d[i]];
            H.erase(lower_bound(H.begin(),H.end(),a[d[i]]));
        }
        mi=min(tmp/m,mi);
        ma=max(tmp/m,ma);
    }
    if(H.size()+k*m!=n){
        double tmp;
        tmp=0;
        for(i=0;i<m;i++)tmp+=H[i];
        mi=min(tmp/m,mi);
        ma=max(tmp/m,ma);
        tmp=0;
        for(i=0;i<m;i++)tmp+=H[H.size()-1-i];
        mi=min(tmp/m,mi);
        ma=max(tmp/m,ma);

    }
    printf("%.10lf %.10lf\n",mi,ma);
    return 0;
}