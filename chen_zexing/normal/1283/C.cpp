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
vector <int> v,wr;
int f[200005],a[200005],ans[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[a[i]]=1;
        for(int i=1;i<=n;i++) if(!f[i]) v.push_back(i);
        int x=0,fl=0,p;
        for(int i=1;i<=n;i++){
            if(a[i]) ans[i]=a[i];
            else if(v[x]!=i) ans[i]=v[x++];
            else wr.push_back(i),fl=1,p=x++;
        }
        if(fl) {
            while(wr.size()==1){
                fl=0;
                swap(v[(p+1)%v.size()],v[p]);
                wr.clear();
                x=0;
                for(int i=1;i<=n;i++){
                    if(a[i]) ans[i]=a[i];
                    else if(v[x]!=i) ans[i]=v[x++];
                    else wr.push_back(i),fl=1,p=x++;
                }
            }
            if(fl){
            for (int i = 0;i<wr.size()-1;i++) ans[wr[i]]=wr[i+1];
            ans[wr[wr.size()-1]]=wr[0];}
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    }
    return 0;
}