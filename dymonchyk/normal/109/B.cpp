#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

vector <int> v;

void go(int num = 0)
{
    if (num!=0&&num<=1000000000) v.push_back(num);
    if (10LL*num>=1000000000LL) return;
    go(10*num+4);
    go(10*num+7);
}

int inter(int l1,int r1,int l2,int r2)
{
    if (min(r1,r2)-max(l1,l2)+1>=0) return min(r1,r2)-max(l1,l2)+1;
    return 0;
}

double pp(int l1,int r1,int l2,int r2,int k)
{
    double ans=0;
    for(int l=l1;l<=r1;l++)
        for(int r=l2;r<=r2;r++)
        {
            int L=min(l,r),R=max(l,r),cnt=0;
            for(int i=1;i<v.size()-1&&v[i]<=R;i++)
                if (v[i]>=L) cnt++;
            if (cnt==k) ans++;
        }
    ans/=(r1-l1+1); ans/=(r2-l2+1);
    return ans;
}

long double solve(int l1,int r1,int l2,int r2,int k)
{
    ll tot=1LL*(r1-l1+1)*(r2-l2+1);
    long double cnt=0;
    for(int i=1;i<v.size()-1;i++)
        if (i+k-1<v.size()-1)
        {
            cnt+=1LL*inter(l1,r1,v[i-1]+1,v[i])*inter(l2,r2,v[i+k-1],v[i+k]-1);
//          if (i<5) cout << inter(l1,r1,v[i-1]+1,v[i]) << "    " << inter(l2,r2,v[i+k-1],v[i+k]-1) << endl;
        }
//  cout << endl;
    for(int i=1;i<v.size()-1;i++)
        if (i+k-1<v.size()-1)
        {
            cnt+=1LL*inter(l2,r2,v[i-1]+1,v[i])*inter(l1,r1,v[i+k-1],v[i+k]-1);
//          if (i<5) cout << inter(l1,r1,v[i-1]+1,v[i]) << "    " << inter(l2,r2,v[i+k-1],v[i+k]-1) << endl;
        }
    if (k==1)
    {
        for(int i=1;i<v.size()-1;i++)
            if (l1<=v[i]&&v[i]<=r1&&l2<=v[i]&&v[i]<=r2) cnt--;
    }
    long double ans=cnt;
    ans/=(r1-l1+1); ans/=(r2-l2+1);
    return ans;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    go();
    v.push_back(-1);
    v.push_back(1000000007);
    sort(v.begin(),v.end());
    int l1,r1,l2,r2,k,K=30;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
/*  for(l1=1;l1<K;l1++)
        for(r1=l1;r1<K;r1++)
            for(l2=1;l2<K;l2++)
                for(r2=l2;r2<K;r2++)
                    for(k=1;k<10;k++)
                        if (fabs(solve(l1,r1,l2,r2,k)-pp(l1,r1,l2,r2,k))>1e-7)
                        {
                            cout << l1 << " " << r1 << "    " << l2 << "    " << r2 << "    " << k << endl;
                        }*/
    printf("%.9lf\n",solve(l1,r1,l2,r2,k));
    if (k==0) return -1;
//  printf("%.12lf\n",pp(l1,r1,l2,r2,k));
//  cout << cnt << endl;
    return 0;
}