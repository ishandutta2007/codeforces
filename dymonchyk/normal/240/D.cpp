#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <complex>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

int a1[100005];
int a2[100005];
int a[200002];
vector <int> ans;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a1[i]);
    scanf("%d",&m);
    for(int i=0;i<m;++i)
        scanf("%d",&a2[i]);
/*  int l=0,r=n-1;
    while(l<r) {
        swap(a1[l],a1[r]);
        ++l; --r;
    }
    l=0,r=m-1;
    while(l<r) {
        swap(a2[l],a2[r]);
        ++l; --r;
    }*/
    int size=0,p1=n-1,p2=m-1,last=0;
    bool f=true;
    while(p1>=0||p2>=0) {
        if (p1==-1) {
            ans.push_back(n+1+p2);
            a[size++]=a2[p2]; --p2;
        } else if (p2==-1) {
            ans.push_back(p1+1);
            a[size++]=a1[p1]; --p1;
        } else {
            if (a1[p1]==last||a2[p2]!=last) {
                ans.push_back(p1+1);
                last=a1[p1];
                a[size++]=a1[p1]; --p1;
            } else {
                ans.push_back(n+1+p2);
                last=a2[p2];
                a[size++]=a2[p2]; --p2;
            }
        }
    }
    for(int i=ans.size()-1;i>=0;--i) {
        if (i!=ans.size()-1) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
/*  int l=0,r=size-1;
    while(l<r) {
        swap(a[l],a[r]);
        ++l; --r;
    }*/
    int cnt=0,p=0;
    while(p<size&&a[p]==0) ++p;
    while(p<size) {
        if (p==0||a[p-1]!=a[p]) ++cnt;
        ++p;
    }
    printf("%d\n",cnt);
    p=size-1; f=true;
    while(p>=0) {
        if (p==0) {
            if (a[p]==1) {
                if (!f) printf(" ");
                f=false;
                printf("%d",size-p);
            }
        } else {
            if (a[p-1]!=a[p]) {
                if (!f) printf(" ");
                f=false;
                printf("%d",size-p);
            }
        }
        --p;
    }
    printf("\n");
    return 0;
}