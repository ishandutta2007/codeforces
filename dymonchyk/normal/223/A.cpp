#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <ctime>

using namespace std;

char str[100005];
map <int,int> f;
vector <int> open;
vector <int> pos,close;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str); int n=strlen(str); f[0]=-1;
    int dif=0,ok=0,best=-1,l=0,r=-1;
    int last=-1,lp=-1,lc=-1,cc=0;
    for(int i=0;i<n;++i) {
        if (str[i]=='['||str[i]==']') {
            if (str[i]=='[') {
                dif++;
                open.push_back(0);
                pos.push_back(last!=-1 ? lp : i);
                close.push_back(last!=-1 ? lc : cc);
                last=-1; lp=-1; lc=-1;
            } else {
                last=-1; lp=-1; lc=-1;
                if (open.size()==0||open.back()!=0) {
                    open.clear();
                    pos.clear();
                    close.clear();
                    dif=0;
                    continue;
                } else {
                    --dif; ++cc;
                    int p=pos.back(),c=close.back();
                    if (cc-c>best) {
                        best=cc-c;
                        l=p; r=i;
                    }
                    if (dif==0) {
                        last=1; lp=p; lc=c;
                    } else {
                        last=1; lp=p; lc=c;
                    }
                    open.pop_back();
                    pos.pop_back();
                    close.pop_back();
                }
            }
        } else {
            if (str[i]=='(') {
                dif++;
                open.push_back(1);
                pos.push_back(last!=-1 ? lp : i);
                close.push_back(last!=-1 ? lc : cc);
                last=-1; lp=-1; lc=-1;
            } else {
                last=-1; lp=-1; lc=-1;
                if (open.size()==0||open.back()!=1) {
                    open.clear();
                    pos.clear();
                    close.clear();
                    dif=0;
                    continue;
                } else {
                    --dif;
                    int p=pos.back(),c=close.back();
                    if (cc-c>best) {
                        best=cc-c;
                        l=p; r=i;
                    }
                    if (dif==0) {
                        last=1; lp=p; lc=c;
                    } else {
                        last=1; lp=p; lc=c;
                    }
                    open.pop_back();
                    pos.pop_back();
                    close.pop_back();
                }
            }
        }
    }
    if (best!=-1) {
        printf("%d\n",best);
        for(int i=l;i<=r;++i)
            printf("%c",str[i]);
        printf("\n");
    } else puts("0");
    return 0;
}