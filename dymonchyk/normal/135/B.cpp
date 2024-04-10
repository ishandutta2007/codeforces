#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int x[8],y[8];

int bc(int x)
{
    int res=0;
    while(x)
    {
        res+=x&1;
        x>>=1;
    }
    return res;
}

int dist(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

bool isRight(int a,int b,int c)
{
    return dist(a,c)==dist(a,b)+dist(b,c);
}

bool isSquare(vector <int> v)
{
    sort(v.begin(),v.end());
    do{
        int d=dist(v[0],v[1]);
        if (d==0) continue;
        bool ok=true;
        for(int i=1;i<4;i++)
        {
            if (d!=dist(v[i],v[(i+1)%4])) ok=false;
        }
        if (!ok) continue;
        if (!isRight(v[0],v[1],v[2])||!isRight(v[1],v[2],v[3])||!isRight(v[2],v[3],v[0])||!isRight(v[3],v[0],v[1]))
            continue;
        return true;
    }while(next_permutation(v.begin(),v.end()));
    return false;
}

bool isRectangle(vector <int> v)
{
    sort(v.begin(),v.end());
    do{
        if (dist(v[0],v[1])==0||dist(v[1],v[2])==0) continue;
        if (!isRight(v[0],v[1],v[2])||!isRight(v[1],v[2],v[3])||!isRight(v[2],v[3],v[0])||!isRight(v[3],v[0],v[1]))
            continue;
        return true;
    }while(next_permutation(v.begin(),v.end()));
    return false;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    for(int i=0;i<8;i++)
        cin >> x[i] >> y[i];
    for(int mask=0;mask<(1<<8);mask++)
    {
        if (bc(mask)!=4) continue;
        vector <int> sq,rec;
        for(int i=0;i<8;i++)
            if (mask&(1<<i)) sq.push_back(i);
            else rec.push_back(i);
        if (isSquare(sq)&&isRectangle(rec))
        {
            printf("YES\n%d %d %d %d\n%d %d %d %d\n",sq[0]+1,sq[1]+1,sq[2]+1,sq[3]+1,rec[0]+1,rec[1]+1,rec[2]+1,rec[3]+1);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}