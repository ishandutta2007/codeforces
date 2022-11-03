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
#pragma comment (linker,"/STACK:128000000")

using namespace std;

vector < vector <int> > g;

bool ok(const vector <int> & v,int key) {
    int l=0,r=v.size();
    while(r-l>1) {
        int m=(l+r)>>1;
        if (v[m]<=key) l=m;
        else r=m;
    }
    return v[l]==key;
}

int t,h;
int cool[100005];
vector <int> l1,l2;

void calc_t(int n) {
    int v,u,top;
    for(int i=0;i<n;++i) {
        for(int j=0;j<g[i].size();++j) {
            v=i; u=g[i][j];
            int ret=0;
            if (v>u) continue;
            if (g[v].size()>g[u].size()) swap(u,v);
            if (g[v].size()<=min(h,t)||g[u].size()<=max(h,t)) continue;
            if (g[u].size()+g[v].size()<15*g[v].size()) {
                int l=0,r=0;
                while(l<g[u].size()&&r<g[v].size()) {
                    if (g[u][l]==g[v][r]) ++ret,++l,++r;
                    else {
                        if (g[u][l]<g[v][r]) ++l;
                        else ++r;
                    }
                }
            } else {
                for(int e=0;e<g[v].size();++e) {
                    top=g[v][e];
                    ret+=ok(g[u],top);
                }
            }
            int a=(int)g[u].size()-1-ret,b=(int)g[v].size()-1-ret;
            if (max(0,h-a)+max(0,t-b)<=ret) {
                puts("YES");
                printf("%d %d\n",u+1,v+1);
                if (g[u].size()+g[v].size()<15*g[v].size()) {
                    int l=0,r=0;
                    while(l<g[u].size()&&r<g[v].size()) {
                        if (g[u][l]==g[v][r]) {
                            cool[g[u][l]]=1;
                            ++ret,++l,++r;
                        }
                        else {
                            if (g[u][l]<g[v][r]) ++l;
                            else ++r;
                        }
                    }
                } else {
                    for(int e=0;e<g[v].size();++e) {
                        top=g[v][e];
                        if (ok(g[u],top)) {
                            ret++;
                            cool[top]=1;
                        }
                    }
                }
                int can=max(0,h-a);
                for(int e=0;e<g[u].size()&&h;++e) {
                    top=g[u][e];
                    if (top==v) continue;
                    if (cool[top]) {
                        if (can&&cool[top]==1) {
                            --can; --h;
                            l1.push_back(top);
                            cool[top]=2;
                        }
                    } else {
                        --h;
                        l1.push_back(top);
                    }
                }
                can=max(0,t-b);
                for(int e=0;e<g[v].size()&&t;++e) {
                    top=g[v][e];
                    if (top==u) continue;
                    if (cool[top]) {
                        if (can&&cool[top]==1) {
                            --can; --t;
                            l2.push_back(top);
                        }
                    } else {
                        --t;
                        l2.push_back(top);
                    }
                }
                for(int e=0;e<l1.size();++e) {
                    if (e) printf(" ");
                    printf("%d",l1[e]+1);
                }
                printf("\n");
                for(int e=0;e<l2.size();++e) {
                    if (e) printf(" ");
                    printf("%d",l2[e]+1);
                }
                printf("\n");
                return;
            }
            swap(u,v); swap(a,b);
            if (max(0,h-a)+max(0,t-b)<=ret) {
                puts("YES");
                printf("%d %d\n",u+1,v+1);
                swap(u,v); swap(a,b);
                if (g[u].size()+g[v].size()<15*g[v].size()) {
                    int l=0,r=0;
                    while(l<g[u].size()&&r<g[v].size()) {
                        if (g[u][l]==g[v][r]) {
                            cool[g[u][l]]=1;
                            ++ret,++l,++r;
                        }
                        else {
                            if (g[u][l]<g[v][r]) ++l;
                            else ++r;
                        }
                    }
                } else {
                    for(int e=0;e<g[v].size();++e) {
                        top=g[v][e];
                        if (ok(g[u],top)) {
                            ret++;
                            cool[top]=1;
                        }
                    }
                }
                int can=max(0,t-a);
                for(int e=0;e<g[u].size()&&t;++e) {
                    top=g[u][e];
                    if (top==v) continue;
                    if (cool[top]) {
                        if (can&&cool[top]==1) {
                            --can; --t;
                            l1.push_back(top);
                            cool[top]=2;
                        }
                    } else {
                        --t;
                        l1.push_back(top);
                    }
                }
                can=max(0,h-b);
                for(int e=0;e<g[v].size()&&h;++e) {
                    top=g[v][e];
                    if (top==u) continue;
                    if (cool[top]) {
                        if (can&&cool[top]==1) {
                            --can; --h;
                            l2.push_back(top);
                        }
                    } else {
                        --h;
                        l2.push_back(top);
                    }
                }
                for(int e=0;e<l2.size();++e) {
                    if (e) printf(" ");
                    printf("%d",l2[e]+1);
                }
                printf("\n");
                for(int e=0;e<l1.size();++e) {
                    if (e) printf(" ");
                    printf("%d",l1[e]+1);
                }
                printf("\n");
                return;
            }
        }
    }
    puts("NO");
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,c;
    scanf("%d%d%d%d\n",&n,&m,&h,&t);
    g.resize(n);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;++i)
        sort(g[i].begin(),g[i].end());
    calc_t(n);
/*  vector <int> vv;
    vv.push_back(0);
    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(3);
    cout << ok(vv,-1) << endl;
    cout << ok(vv,0) << endl;
    cout << ok(vv,1) << endl;
    cout << ok(vv,2) << endl;
    cout << ok(vv,3) << endl;
    cout << ok(vv,4) << endl;
*/  return 0;
}