#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef pair<int,int> PII;
typedef __int64 LL;

LL node[400002][6];
int sz[400002];
vector<int> A;

void insert(int at, int low, int hi, int x)
{
    if(x<A[low] || x>A[hi]) return;

    int i,j;

    sz[at]++;
    if(low==hi)
    {
        for(i=0;i<5;i++) node[at][i]=0;
        node[at][0]=x;
        return;
    }

    int mid = (low+hi)/2;
    if(x<=A[mid]) insert(at*2,low,mid,x);
    else insert(at*2+1,mid+1,hi,x);

    for(i=0;i<5;i++) node[at][i]=node[at*2][i];

    for(i=0;i<5;i++)
    {
        node[at][(i + sz[at*2])%5] += node[at*2+1][i];
    }

}

void del(int at, int low, int hi, int x)
{
    int i,j;

    if(x<A[low] || x>A[hi]) return;

    sz[at]--;
    if(low==hi)
    {
        for(i=0;i<5;i++) node[at][i]=0;
        node[at][0]=0;
        return;
    }

    int mid = (low+hi)/2;
    if(x<=A[mid]) del(at*2,low,mid,x);
    else del(at*2+1,mid+1,hi,x);
    for(i=0;i<5;i++) node[at][i]=node[at*2][i];

    for(i=0;i<5;i++)
    {
        node[at][(i + sz[at*2])%5] += node[at*2+1][i];
    }

}

vector<PII> X;

int main()
{
    int n;
    int i,a,j;
    char name[100];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",name);

        if(name[0]=='s')
            X.push_back(PII(0,-1));
        else if(name[0]=='a')
        {
            scanf("%d",&a);
            X.push_back(PII(1,a));
            A.push_back(a);
        }
        else
        {
            scanf("%d",&a);
            X.push_back(PII(2,a));
            A.push_back(a);
        }
    }

    sort(A.begin(),A.end());
    for(i=1,j=0;i<A.size();i++)
        if(A[j]==A[i]) continue;
        else A[++j] = A[i];

    int sz = j+1;

    for(i=0;i<X.size();i++)
    {
        if(X[i].first==0) printf("%I64d\n",node[1][2]);
        else if(X[i].first==1) insert(1,0,sz-1,X[i].second);
        else del(1,0,sz-1,X[i].second);
    }

    return 0;
}