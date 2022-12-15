#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
long long a[100005];
struct step{
    string op;
    int t;
};
vector <step> v;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int tot=2*(n-1)*m+2*(m-1)*n;
        if(k>tot){
            puts("NO");
            return 0;
        }
        if(m==1){
            if(k<=n-1) printf("YES\n1\n%d D\n",k);
            else printf("YES\n2\n%d D\n%d U\n",n-1,k-n+1);
            return 0;
        }
        if(k<=m-1){
            v.push_back(step{"R",k});
            k=0;
            continue;
        }
        v.push_back(step{"R",m-1});
        k-=m-1;
        if(k<=m-1){
            v.push_back(step{"L",k});
            k=0;
            continue;
        }
        v.push_back(step{"L",m-1});
        k-=m-1;
        for(int i=2;i<=n&&k;i++){
            if(k<=3*m-3){
                if(k>=3) v.push_back(step{"DRU",k/3});
                k%=3;
                if(k==1) v.push_back(step{"D",k});
                else if(k==2) v.push_back(step{"DR",1});
                k=0;
                continue;
            }
            v.push_back(step{"DRU",m-1});
            k-=3*m-3;
            v.push_back(step{"D",1});
            k--;
            if(k<=m-1){
                if(!k) continue;
                v.push_back(step{"L",k});
                k=0;
                continue;
            }
            v.push_back(step{"L",m-1});
            k-=m-1;
        }
        if(k) v.push_back(step{"U",k});
    }

    puts("YES");
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i].t);
        cout<<v[i].op<<endl;
    }
    return 0;
}