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
int a[100005],f[100005];
vector <int> v;
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=0;
        int now=n,pos=n;
        v.clear();
        while(now){
            while(f[now]==1&&now) now--;
            if(!now) break;
            int st=pos;
            while(a[pos]!=now) pos--,f[a[pos+1]]=1;
            f[now]=1;
            now--,pos--;
            for(int j=pos+1;j<=st;j++) v.push_back(a[j]);
            //cout<<pos<<" "<<now<<" "<<st<<endl;
        }
        //cout<<v.size()<<endl;
        for(int i=1;i<=n;i++) printf("%d ",v[i-1]);
        puts("");
    }
    return 0;
}