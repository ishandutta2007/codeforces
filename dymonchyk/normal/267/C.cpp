#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int a[5005],b[5005],c[5005];
double m[102][102];

int main() {
    int n,e,deg=0;
    scanf("%d%d",&n,&e);
    for(int i=0;i<e;++i) {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        --a[i]; --b[i];
    }
    for(int i=1;i<n-1;++i) {
        for(int j=0;j<e;++j) {
            if (a[j]==i) {
                m[i-1][b[j]]+=1;
                m[i-1][a[j]]-=1;
            }
            if (b[j]==i) {
                m[i-1][b[j]]-=1;
                m[i-1][a[j]]+=1;
            }
        }
    }
    const double eps=1e-8;
    for(int i=0;i<n-2;++i) {
        int ind=-1;
        for(int j=i;j<n-2;++j)
            if (fabs(m[j][i+1])>eps) {
                ind=j;
                break;
            }
        if (ind==-1) {
//          puts("fail\n");
//          return 0;
            continue;
        }
        for(int j=0;j<n;++j)
            swap(m[i][j],m[ind][j]);
        double a=m[i][i+1];
        for(int j=i+1;j<n;++j)
            m[i][j]/=a;
        for(int j=i+1;j<n-2;++j) {
            double coef=-m[j][i+1];
            for(int t=i+1;t<n;++t)
                m[j][t]+=m[i][t]*coef;
        }
    }
    for(int i=n-3;i>=0;--i) {
        for(int j=i-1;j>=0;--j) {
            double coef=-m[j][i+1];
            for(int t=i+1;t<n;++t)
                m[j][t]+=m[i][t]*coef;
        }
    }
    m[n-2][n-2]=1; m[n-2][n-1]=-1;
/*  for(int i=0;i<=n-2;++i) {
        for(int j=0;j<n;++j)
            cout << m[i][j] << "    ";
        cout << endl;
    }*/
    double l=0,r=1e+9;
    for(int i=0;i<e;++i) {
        if ((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)>eps) {
            r=min(r,c[i]/((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)));
            l=max(l,-c[i]/((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)));
        }
        if ((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)<-eps) {
            l=max(l,c[i]/((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)));
            r=min(r,-c[i]/((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)));
        }
    }
    if (l-eps>r) r=0;
    double ans=0;
    for(int i=0;i<e;++i) {
        if (b[i]==n-1)
            ans+=r*((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0));
        if (a[i]==n-1)
            ans-=r*((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0));
    }
    printf("%.6lf\n",ans+1e-8);
    for(int i=0;i<e;++i) {
        printf("%.6lf\n",r*((a[i] ? m[a[i]-1][n-1] : 0)-(b[i] ? m[b[i]-1][n-1] : 0)));
    }
    return 0;
}