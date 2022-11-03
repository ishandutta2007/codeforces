#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <memory.h>
#include <algorithm>
#pragma comment(linker,"/STACK:64000000")

using namespace std;

vector <int> v;
int a[100005];

int fen[4][100005];

void upd(int i,int pos,int n,int add) {
    for(;pos<n;pos|=(pos+1))
        fen[i][pos]+=add;
}

long long fnd(int i,int pos) {
    long long ret=0;
    for(;pos>=0;pos=(pos&(pos+1))-1)
        ret+=fen[i][pos];
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n; long long k;
    cin >> n >> k;
    for(int i=0;i<n;++i) {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<n;++i)
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    for(int i=2;i<n;++i)
        upd(2,a[i],n,1);
    int l=1,r=1; long long inv=0,ci=(a[0]>a[1])+(n>2 ? fnd(2,a[1]-1) : 0);
    for(int i=0;i<n;++i) {
        inv+=fnd(0,n-1-a[i]-1);
        upd(0,n-1-a[i],n,1);
    }
    if (inv<=k) {
        cout << 1LL*n*(n-1)/2 << endl;
        return 0;
    }
//  cout << inv << endl;
    memset(fen[0],0,sizeof(fen[0]));
    upd(0,n-1-a[0],n,1);
    long long mn=inv-k,ans=0;
    int cr=2;
    upd(1,n-1-a[0],n,1); upd(1,n-1-a[1],n,1);
    upd(3,n-1-a[1],n,1);
    for(int i=1;i<n;++i) {
        while(cr<n-1&&ci<mn) {
            ci+=fnd(2,a[cr]-1);
            ci+=fnd(1,n-1-a[cr]-1);
            ci-=fnd(3,n-1-a[cr]-1);
            upd(1,n-1-a[cr],n,1);
            upd(2,a[cr],n,-1);
            upd(3,n-1-a[cr],n,1);
            ++cr;
        }
        if (ci>=mn) ans+=(n-1)-cr+1;
        ci-=fnd(0,n-1-a[i]-1);
        ci-=fnd(2,a[i]-1);
        upd(0,n-1-a[i],n,1);
        upd(3,n-1-a[i],n,-1);
    }
    cout << ans << endl;
    return 0;
}