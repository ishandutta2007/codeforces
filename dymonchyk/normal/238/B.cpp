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
#include <map>
#include <set>

using namespace std;

vector < pair <int,int> > v;
int what[100005];

int solve(int n,int h) {
    int ans=100000000;
    for(int mask=(1<<n)-1;mask>=0;--mask) {
        int mx=0,mn=100000000;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j) {
                if (((mask&(1<<j))>0)!=((mask&(1<<i))>0)) {
                    mx=max(mx,v[i].first+v[j].first+h);
                    mn=min(mn,v[i].first+v[j].first+h);
                } else {
                    mx=max(mx,v[i].first+v[j].first);
                    mn=min(mn,v[i].first+v[j].first);
                }
            }
        ans=min(ans,mx-mn);
    }
    return ans;
}

int go(int n,int h,bool need = false) {
    sort(v.begin(),v.end());
    int mx=v[0].first+v[1].first+h,mn=v[0].first+v[1].first+h;
    what[v[0].second]=1; what[v[1].second]=2;
    int last1=v[0].first,last2=v[1].first;
    for(int i=2;i<n;++i) {
        if (v[0].first+v[i].first<mn) {
            what[v[i].second]=2;
            mn=min(mn,v[i].first+v[1].first);
            mn=min(mn,v[i].first+v[0].first+h);
            mx=max(mx,v[i].first+last2);
            mx=max(mx,v[i].first+last1+h);
            last2=v[i].first;
        } else {
            if (max(last1+v[i].first,last2+v[i].first+h)<max(last2+v[i].first,last1+v[i].first+h)) {
                what[v[i].second]=1;
                mx=max(mx,max(last1+v[i].first,last2+v[i].first+h));
                last1=v[i].first;
            } else {
                what[v[i].second]=2;
                mx=max(mx,max(last2+v[i].first,last1+v[i].first+h));
                last2=v[i].first;
            }
        }
    }
//  cout << mn << " " << mx << endl;
    mx-=mn;
    if (mx>(v.back().first+v[n-2].first)-(v[0].first+v[1].first)) {
        mx=(v.back().first+v[n-2].first)-(v[0].first+v[1].first);
        for(int i=0;i<n;++i) what[i]=1;
    }
    if (need) {
        printf("%d\n",mx);
        for(int i=0;i<n;++i) {
            if (i) printf(" ");
            printf("%d",what[i]);
        }
        printf("\n");
    }
    return mx;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,h,a;
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        v.push_back(make_pair(a,i));
    }
    go(n,h,true);
//  cout << solve(n,h) << endl;
//  cout << go(n,h) << endl;
/*  for(int test=0;test<50;++test) {
        n=rand()%15+2; h=rand()%5;
        v.clear();
        for(int i=0;i<n;++i)
            v.push_back(make_pair(rand()%5,i));
        if (solve(n,h)!=go(n,h)) {
            cout << "fail\n";
            cout << n << "  " << h << endl;
            for(int i=0;i<n;++i)
                cout << v[i].first << " ";
            cout << endl;
            cout << solve(n,h) << endl;
            go(n,h,true);
            break;
        }
    }*/
    return 0;
}